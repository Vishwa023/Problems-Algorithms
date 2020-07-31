#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ll MOD = 1e9 + 7; 
const ll N = 1e5 + 10;

struct Node{
    ll data;
    Node *next;
    Node() : data(0), next(nullptr) {};
    Node(ll x) : data(x), next(nullptr) {};
};

Node *rear, *front;

void Queue()
{
    rear = NULL;
    front = NULL;
}

void enQueue(ll x)
{
    Node *temp = new Node(x);
    if(front == NULL)
    {
        rear = temp;
        front = temp;
        return;
    }
    rear -> next = temp;
    rear = temp;
}

void deQueue()
{
    if(front == NULL)
        return;
    Node *temp = new Node();
    temp = front;
    front = front -> next;
    if(front == NULL)
    {
        rear = NULL;
    }
    delete(temp);
}

void display()
{
    Node *temp = new Node();
    if(front == NULL)
    {
        cout << "Queue is empty!!" << endl;
        return;
    }
    temp = front;
    while(temp != NULL)
    {
        cout << temp -> data << endl;
        temp = temp -> next;
    }
}

int main()
{
    IOS;
    ll operation;
    cin >> operation;
    Queue();
    while(operation--)
    {
        // enQueue : eq;
        // deQueue : dq;
        // Display : d;
        string s; cin >> s;
        if(s == "eq")
        {
            ll ele; cin >> ele;
            enQueue(ele);
        } 
        if(s == "dq")
            deQueue();
        if(s == "d")
            display();
    }
    return 0;
}

