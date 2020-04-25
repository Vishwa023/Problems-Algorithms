
// Prim's Algorithm for finding minimum spanning tree cost

// Algorithm Steps:

// Maintain two disjoint sets of vertices. One containing vertices that are in the growing spanning tree and other that are not in the growing spanning tree.
// Select the cheapest vertex that is connected to the growing spanning tree and is not in the growing spanning tree and add it into the growing spanning tree. This can be done using Priority Queues. Insert the vertices, that are connected to growing spanning tree, into the Priority Queue.
// Check for cycles. To do that, mark the nodes which have been already selected and insert only those nodes in the Priority Queue that are not marked.

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<pair<int,int>>g[MAX];
bool vis[MAX];

int prim(int x)
{
    priority_queue<PII,vector<PII>,greater<PII>>pq;
    pq.push({0,x});
    int cost=0;
    PII p;
    while(!pq.empty())
    {
        p=pq.top();
        pq.pop();
        x=p.second;
        if(vis[x])continue;
        vis[x]=true;
        cost+=p.first;
        for(auto it:g[x])
        {
            if(!vis[it.second])
            {
                pq.push(it);
            }
        }
    }
    return cost;
}

int main()
{
    IOS;
    int nodes,edges;
    cin >> nodes >> edges;

    for(int i=1;i<=edges;i++)
    {
        int weight,u,v;
        cin >> weight >> u >> v;
        g[u].push_back({weight,v});
        g[v].push_back({weight,u});
    }
    
    int mn_cost=prim(1);
    cout << mn_cost << endl;
    return 0;
}

// TEST CASE
// input:
// 5 7 // # of nodes and edges
// 1 1 2 
// 7 1 3
// 5 2 3 
// 4 2 4
// 2 4 5 
// 3 2 5
// 6 3 5

// Output:
// 11 --> minimum spanning tree cost