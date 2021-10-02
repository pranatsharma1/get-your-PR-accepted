#include<bits/stdc++.h>
using namespace std;

#define fastIO              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int                 long long

// Bipartite graph : A graph is said to be bipartite if it can be 
// coloured using only 2 colors, such that no adjacent vertices 
// have the same color

const int N = 1e5 + 7;
vector<int> adj[N]; // adjacency list for representing the graph
vector<bool>vis(N,false);   // vector used to mark a given node as visited or not
vector<int>col(N,-1);   // vector used to store the color of a given node

// function to check bipartiteness in the graph using dfs call
bool bipartiteCheck(int node, int color)
{

    vis[node] = true;   // marking this node as visited
    col[node] = color;  // assigning the color to the node
    
    // traversing the adjacent nodes of current node
    for(int i : adj[node])
    {
        if(!vis[i])
        {
            if(!bipartiteCheck(i,color ^ 1))
                return false;
        }
        else if(col[i] == col[node])
            return false;
    }

    return true;

}

void solve()
{

    int n, m;
    cin >> n >> m;

    // crating the graph
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            if(!bipartiteCheck(i,1))
            {
                cout << "Graph is not a bipartite graph\n";
                return ;
            }
        }
    }

    cout << "Graph is a bipartite graph\n";


}

int32_t main()
{

    fastIO
    cout << setprecision(15) << fixed;

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case #"<<i<<": \n";
        solve();
    }

    return 0;

}