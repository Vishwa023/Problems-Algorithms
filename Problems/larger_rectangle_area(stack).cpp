#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
stack<int>s;
int main()
{
    IOS;
    int n;
    cin >> n;
    int heights[n+5];
    for(int i=0;i<n;i++)cin >> heights[i];

    int i = 0;
    int max_area = 0;
    while(i<n)
    {
        if(s.empty() || heights[s.top()] <= heights[i])
        {    
            s.push(i++);
        } 
        else
        {
            int tp = s.top();
            s.pop();
            
            int area_with_tp;
            // int area_with_tp = heights[tp] * (s.empty() ? i : i - s.top() -1);

            cout << i << " " << s.top() << endl;
            if(s.empty())area_with_tp=heights[tp]*i;
            else area_with_tp=heights[tp]*(i-s.top()-1);
             
            max_area = max(max_area,area_with_tp);
        }
    }
    
    while(s.empty() == false)
    {
        int tp = s.top();
        s.pop();
        int area_with_tp;
        // int area_with_tp = heights[tp] * (s.empty() ? i : i - s.top() -1);
        
        if(s.empty())area_with_tp=heights[tp]*i;
        else area_with_tp=heights[tp]*(i-s.top()-1);
        max_area = max(max_area,area_with_tp);
    }

    cout << max_area;
    return 0;
}

// TEST CASE
// Input:
// 5 -> n
// 1 2 4 5 3 ->heights
// Output:
// 9