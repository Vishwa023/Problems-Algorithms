
// Sliding Window Maximum (Maximum of all subarrays of size k)

// Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    IOS;
    ll n,k;
    cin >> n >> k;

    ll a[n+5];
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
    }

    
    // Create a Double Ended Queue, Q that will store indexes of array elements 
    // The queue will store indexes of useful elements in every window and it will 
    // maintain decreasing order of values from front to rear in Q, i.e., 
    // arr[Q.front[]] to arr[Q.rear()] are sorted in decreasing order 
    deque<ll>Q(k);

    for(ll i=0;i<k;i++)
    {
        // For every element, the previous smaller elements are useless so 
        // remove them from Q
        while(!Q.empty() && a[i]>=a[Q.back()])
        {
            Q.pop_back();
        }
        // Add new element at rear of queue 
        Q.push_back(i);
    }

    for(ll i=k;i<n;i++)
    {
        // The element at the front of the queue is the largest element of 
        // previous window, so print it 
        cout << a[Q.front()] << " ";

        // Remove the elements which are out of this window 
        while(!Q.empty() && a[Q.front()]<=(i-k))
        {
            Q.pop_front();
        }

        // Remove all elements smaller than the currently 
        // being added element (remove useless elements) 
        while(!Q.empty() && a[i]>=a[Q.back()])
        {
            Q.pop_back();
        }

        Q.push_back(i);
    }

    cout << a[Q.front()] << " ";
    return 0;
}

