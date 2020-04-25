// Kruskal's Algorithm for finding Minimum Spanning Tree
// What is a Minimum Spanning Tree?
// The cost of the spanning tree is the sum of the weights of all the edges in the tree. There can be many spanning trees. Minimum spanning tree is the spanning tree where the cost is minimum among all the spanning trees. There also can be many minimum spanning trees.

// Time Complexity : O(ElogV)

// Algorithm Steps:

// Sort the graph edges with respect to their weights.
// Start adding edges to the MST from the edge with the smallest weight until the edge of the largest weight.
// Only add edges which doesn't form a cycle , edges which connect only disconnected components.

// So, now for detecting cycle, we are using disjoint Set Union Alogorithm.

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int MAX = 1e4 + 5;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int id[MAX];
vector<pair<int,pair<int,int>>>g;

void intialize()
{
    for(int i=0;i<MAX;i++)
    {
        id[i]=i;
    }
}

int root(int x)
{
    while(id[x]!=x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p=root(x);
    int q=root(y);
    id[p]=id[q];
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
        g.push_back({weight,{u,v}});
    }
    
    sort(g.begin(),g.end());

    int mn_cost=0;
    intialize();
    for(int i=0;i<edges;i++)
    {
        int cost=g[i].first;
        int x=g[i].second.first;
        int y=g[i].second.second;
        
        if(root(x) != root(y)) // this is to check if x and y are in same set or not 
        {
            mn_cost+=cost; // if x and y are not in the same set then add cost of an edge of x and y
            union1(x,y); // put x and y in same set
        }
    }

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