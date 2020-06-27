#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll n,k;
	cin >> n >> k;

	ll dp[n+5][k+5];
	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=min(i,k);j++)
		{
			if(j==0 || j==i)
			{
				dp[i][j]=1;
			}
			else
			{
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			}
		}
	}

	cout << dp[n][k];

	return 0;
}

// formula used

// (n,r)=(n-1,r-1)+(n-1,r);

// virender.singh@proptiger.com/aardetechnosoft --> ReactJS

// webdev@123   -->>> JavaScript
// jaydeeperaniya17jd@gmail.com