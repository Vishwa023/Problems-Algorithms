// Dijkstra Algorithm Using Set

// Time Complexity : O(ElogV) --->E : Edges, V : Vertexes 


// 1) Initialize distances of all vertices as infinite.

// 2) Create an empty set.  Every item of set is a pair
//   (weight, vertex). Weight (or distance) is used used
//   as first item  of pair as first item is by default 
//   used to compare two pairs.

// 3) Insert source vertex into the set and make its
//    distance as 0.

// 4) While Set doesn't become empty, do following
//     a) Extract minimum distance vertex from Set. 
//        Let the extracted vertex be u.
//     b) Loop through all adjacent of u and do 
//        following for every vertex v.

//            // If there is a shorter path to v
//            // through u. 
//            If dist[v] > dist[u] + weight(u, v)

//                (i) Update distance of v, i.e., do
//                      dist[v] = dist[u] + weight(u, v)
//                (i) If v is in set, update its distance
//                    in set by removing it first, then
//                    inserting with new distance
//                (ii) If v is not in set, then insert
//                     it in set with new distance
               
// 5) Print distance array dist[] to print all shortest
//    paths. 

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=1e5;
const ll INF=1e9;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<pair<int,int>>g[N];
vector<int>dist(N,INF);
set<pair<int,int>>se;

void dijkstra(int src)
{
    se.insert({0,src});
    dist[src]=0;

    while(!se.empty())
    {
        pair<int,int>p=*se.begin();
        se.erase(se.begin());
        
        int u=p.second;
        for(auto it:g[u])
        {
            int v=it.first;
            int weight=it.second;

            if(dist[v]>dist[u]+weight)
            {
                if(dist[v]!=INF)
                {
                    se.erase(se.find({dist[v],v}));
                }
                dist[v]=dist[u]+weight;
                se.insert({dist[v],v});
            }
        }
    }
}

int main()
{
    int n,edges; // Number of Vertex and Number of edges
    cin >> n >> edges;

    for(int i=1;i<=edges;i++)
    {
        int u,v,w; // u and v are endpoints of edges and w is weight of that edge
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    int s; 
    cin >> s; // take input of source vertex
    dijkstra(s);

    for(int i=0;i<n;i++)
    {
        cout << i << " " << dist[i] << endl; // dist[i] is the distance of vertex i from source vertex
    }

    return 0;
}


// TEST CASE

input: 
9 14 // #of vertex and #of edges
0 1 4 // edges u and v and weight (between u and v)
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6 
7 8 7
0 // source vertex

output:
0 0 // vertex and distance from source vertex
1 4
2 12
3 19
4 21
5 11
6 9
7 8
8 14 
