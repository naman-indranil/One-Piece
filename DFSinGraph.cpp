#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return Breadth First Traversal of given graph.
    void dfsUtil(vector<int> adj[], bool visited[], int u)
    {
        if (visited[u])
            return;

        cout << u << endl;
        visited[u] = true;

        for (int i = 0; i < adj[u].size(); i++)
        {
            dfsUtil(adj, visited, adj[u][i]);
        }
    }
    void dfsOfGraph(int V, vector<int> adj[])
    {
        bool visited[V] = {false};
        dfsUtil(adj, visited, 0);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
                dfsUtil(adj, visited, i);
        }
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        obj.dfsOfGraph(V, adj);
    }
    return 0;
}