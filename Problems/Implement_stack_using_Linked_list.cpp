#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ll MOD = 1e9 + 7; 
const ll N = 1e5 + 10;

struct Node{
    ll data;
    Node *link;
    Node() : data(0), link(nullptr) {};
    Node(ll x) : data(x), link(nullptr) {};
};

Node *top;

void Stack()
{
    top = NULL;
}

void push(ll x)
{
    Node *temp = new Node(x);
    if(top == NULL)
    {
        top = temp;
        return;
    }
    temp -> link = top;
    top = temp;
}

void pop()
{
    if(top == NULL)
    {
        cout << "Stack is empty!!!" << endl;
        return;
    }
    Node *temp = new Node();
    temp = top;
    top = top -> link;
    delete(temp);
}

ll isEmpty() 
{
    return top == NULL;
}

void stack_top()
{
    if(top == NULL)
        cout << "Stack is Empty!!!" << endl;
    else
        cout << top -> data << endl;
}

void display()
{
    if(top == NULL)
    {
        cout << "Stack is empty!!!" << endl;
        return;
    }
    Node *temp = new Node();
    temp = top;
    while(temp != NULL)
    {
        cout << temp -> data << endl;
        temp = temp -> link;
    }
}

int main()
{
    IOS;
    ll operation;
    cin >> operation;
    Stack();
    while(operation--)
    {
        string s;
        cin >> s;
        if(s == "push")
        {
            ll ele; cin >> ele;
            push(ele);
        }
        if(s == "pop")
        {
            pop();
        }
        if(s == "isEmpty")
        {
            if(isEmpty())
                cout << "Stack is Empty!!!" << endl;
            else
                cout << "Stack is not Empty!!!" << endl;
        }
        if(s == "display")
        {
            display();
        }
        if(s == "top")
        {
            stack_top();
        }
    }
    return 0;
}

