// Topological Sort

// If there is an edge between vi and vj then in topological sort order vi should come before vj

// First take vertice which has indegree = 0 and push that vertice into the queue and iterate threw
//  the all neighbour vertices and decrease the indegree value and push the vertices which has 
// indegree value equal to zero

#include<bits/stdc++.h>
using namespace std;

int n, m, indegree[100];
vector<int>g[100];
vector<int>order; //stores the order of the topological sort

int topological_sort()
{
    for(int i = 1; i <= n; i++)
    {
        for(auto it : g[i])
        {
            indegree[it]++;
        }
    }

    queue<int>q;
    for(int i = 1; i <= n; i++)
    {
        if(!indegree[i]) q.push(i);
    }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(auto v : g[u])
        {
            indegree[v]--;
            if(!indegree[v])
            {
                q.push(v);
            }
        }
    }

    if(order.size() == n) return 1;
    else return 0;
}

int main()
{
    cin >> n >> m;
    // n = vertices, m = edges
    for(int i = 0; i < m; i++)
    {
        int x, y; 
        cin >> x >> y;
        // edge between x and y (x towards y)
        g[x].push_back(y);
    }

    int ans = topological_sort();
    if(ans)
    {
        cout << "Topological sort exits" << endl;
        for(int i = 0; i < order.size(); i++)
        {
            cout << order[i] << " ";
        }
    }
    else
    {
        cout << "Topological Sort does not exits" << endl;
    }
    
    return 0;
}