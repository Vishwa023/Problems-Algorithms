#include <bits/stdc++.h> 
using namespace std; 


class Node {
	public:
		int key, val, cnt;
		Node *next, *prev;
		Node(int key, int val) {
			this -> key = key;
			this -> val = val;
			this -> next = NULL;
			this -> prev = NULL;
			this -> cnt = 1;
		}

};

class LFU {
	public: 

		int capacity, minFreq;
		unordered_map<int, Node *>cache;
		unordered_map<int, pair<Node *, Node *>>freqList;

		LFU(int capacity) {
			this -> capacity = capacity;
			this -> minFreq = 0;
		}

		void removeNode(Node *x, int freq) {
			Node* head = freqList[freq].first;
			Node* tail = freqList[freq].second;

			if (head == tail) { // only one node
				freqList.erase(freq);
			} else if (x == head) {
				freqList[freq].first = x->next;
				x->next->prev = NULL;
			} else if (x == tail) {
				freqList[freq].second = x->prev;
				x->prev->next = NULL;
			} else {
				x->prev->next = x->next;
				x->next->prev = x->prev;
			}

			x->next = x->prev = NULL;
		}

		void addNode(Node* x, int freq) {
			if (freqList.find(freq) == freqList.end()) {
				freqList[freq] = { x, x };
			} else {
				Node *head = freqList[freq].first;
				Node *tail = freqList[freq].second;
				x -> next = head;
				head -> prev = x;
				freqList[freq].first = x;
			}
		}

		void updateFreq(Node *curNode) {
			int oldFreq = curNode -> cnt;
			curNode -> cnt += 1;
			removeNode(curNode, oldFreq);
			if (freqList.find(oldFreq) == freqList.end() && minFreq == oldFreq) {
				minFreq = oldFreq + 1;
			}
			addNode(curNode, curNode -> cnt);
		}

		void putValue(int key, int val) {
			if (this -> capacity == 0) return;
			if (cache.find(key) != cache.end()) {
				Node *curNode = cache[key];
				curNode -> val = val;
				updateFreq(curNode);
				return;
			}
			if (cache.size() == this -> capacity) {
				Node *tailNode = freqList[minFreq].second;
				removeNode(tailNode, minFreq);
				cache.erase(tailNode -> key);
				if (freqList[minFreq].first == NULL) {
					freqList.erase(minFreq);
				}
				delete tailNode;
			} 

			Node *newNode = new Node(key, val);
			cache[key] = newNode;
			addNode(newNode, 1);
			minFreq = 1;
			

		}

		int getValue(int key) {
			if (cache.find(key) == cache.end()) return -1;
			Node *curNode = cache[key];
			updateFreq(curNode);
			return curNode -> val;
		}

};

int main() 
{
	LFU* lfuCache = new LFU(2);
    lfuCache->putValue(1, 1);
    lfuCache->putValue(2, 2);
    cout << lfuCache->getValue(1) << endl; // 1
    lfuCache->putValue(3, 3);              // evicts key 2
    cout << lfuCache->getValue(2) << endl; // -1
    cout << lfuCache->getValue(3) << endl; // 3
    cout << lfuCache->getValue(1) << endl; // 1
    return 0;
}

