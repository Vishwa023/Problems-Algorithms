
 
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 5;

// LRU Cache :- we have cache with size of some constant number(capacity) and we have 2 methods 
//             1. get(key) -> this will get the value stored at that key, If key is not present then 
//                 we will return -1
//             2. put(key, value) -> this function will put value at the given key if the cache size is 
//                 full then it will remove least recently used key from the cache and insert this key with
//                 the given value.

//We will  be using doubly linked list for cache and map for tracking 
class Node {
    public:
        int key, val;
        Node *right, *left;
        Node(int key, int val){
            this-> key = key;
            this-> val = val;
            this-> left = NULL;
            this-> right = NULL;
        }
};
 
class LRUCache{
    public:
        Node *head, *tail;
        int capacity, size;
        unordered_map<int, Node *>mp;
        LRUCache(int capacity) {
            this-> capacity = capacity;
            this-> size = 0;
            this->head = NULL;
            this-> tail = NULL;
        }

        void delete_node(Node *x) {
            if(x -> left != NULL) {
                x -> left -> right = x -> right;
            }
            else {
                head = x -> right;
            }
            if(x -> right != NULL) {
                x -> right -> left = x -> left;
            } 
            else {
                tail = x -> left;
            }
            x -> left = NULL;
            x -> right = NULL;
        }

        void insert_node(Node *x) {
            if(head == NULL) {
                head = tail = x;
            }
            else {
                tail -> right = x;
                x -> left = tail;
                tail = x;
            }
        }

        int get(int key) {
            if(mp.find(key) == mp.end()) {
                return -1;
            }
            Node *ans = mp[key]; // Get the value
            delete_node(ans); // delete that node 
            insert_node(ans); // push that node to the back of the queue
            return ans -> val;
        }

        void put(int key, int data) {
            Node *cur = new Node(key, data);
            if(mp.find(key) != mp.end()) { // If I found key value in map then I will change the value of that key and push that node to the back of the queue.
                mp[key] -> val = data;
                delete_node(mp[key]);
                insert_node(mp[key]);
            } else {
                mp[key] = cur;
                if(size == capacity) { // If I don't find key in map and size of the cache is full then I will remove head and insert the new key value to the back of the cache
                    mp.erase(head -> key);
                    delete_node(head);
                    insert_node(cur);
                }
                else{
                    size++;
                    insert_node(cur);
                }
            }
        }
};

int main()
{
    IOS;
    
    LRUCache *lcache = new LRUCache(3);
    lcache -> put(1, 5);
    lcache -> put(2, 4);
    lcache -> put(3, 8);
    lcache -> put(4, 9);
    int ans = lcache -> get(2);
    cout << ans << endl;
    lcache -> put(5, 10);
    int ans1 = lcache -> get(3);
    cout << ans1 << endl;
    return 0;   
}