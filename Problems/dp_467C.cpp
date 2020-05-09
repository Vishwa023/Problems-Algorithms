
// Problem C -  
// Codeforces Round #267 (Div. 2)

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll dp[5005][5005],a[5005];
ll n,m,k;
int main()
{
    IOS;
    cin >> n >> m >> k;
    for(ll i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i]+=a[i-1];
    }
    for(ll i=1;i<=k;i++)
    {
        for(ll j=m;j<=n;j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j-m]+a[j]-a[j-m]);
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    cout << dp[k][n];
    return 0;
}
