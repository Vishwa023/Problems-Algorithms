//Detect cycle in an undirect graph

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 5;
 
ll n, edges, vis[100];
vector<ll>adj[100];

ll dfs(ll x, ll par)
{
    vis[x] = 1;
    for(auto it : adj[x])
    {
        if(!vis[it])
        {
            if(dfs(it, x))
                return true;
        }
        else
        {
            //if the node is already visited then parent should equal to x if it isn't then there should be cycle
            if(par != it)
                return false;               
        }
    }
    return true;
}

int main()
{
    IOS;

    cin >> n >> edges;

    for(ll i = 1; i <= edges; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll chk = dfs(1, 1);

    if(chk)
        cout << "Cycle Exist";
    else
        cout << "Cycle does not Exist";

    return 0;   
}

//Detect cycle in an direct graph

//logic:
//we are maintaing three sets of different colors(white - nodes which are not visited at all,
//Gray - Nodes which neighbours are currently exploring, Black - Nodes which are visited alog with it's neighbours)
//So, while visiting neighbours if we found a Gray node then we can say that there is a cycle in a graph because a node 
//is in gray set means it's neighbours are currently visiting and if we found gray node than it shows path back which creates
//a cycle
//Ex n = 6, edges => 1 2, 1 3, 1 4, 4 5, 5 6, 6 4, 2 3

//color - 0 - white
//color - 1 - gray
//color - 2 - black

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 5;
 
ll n, edges, col[100];
vector<ll>adj[100];

ll dfs(ll x)
{
    col[x] = 1;
    for(auto it : adj[x])
    {
        if(col[it] == 1)
            return 1;
        if(col[it] == 0 && dfs(it))
            return 1;
    }
    col[x] = 2;
    return 0;
}

int main()
{
    IOS;

    cin >> n >> edges;

    for(ll i = 1; i <= edges; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    ll isCycle = 0;

    for(ll i = 1; i <= n; i++)
    {
        if(col[i] == 0)
        {
            if(dfs(i))
                isCycle = 1;
        }
    }

    if(isCycle)
        cout << "Cycle Exist" << endl;
    else
        cout << "Cycle does not Exist" << endl;

    return 0;   
}