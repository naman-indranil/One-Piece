#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find number of strongly connected components in the graph.
    void dfs(bool visited[], vector<int> adj[], stack<int> &s, int u)
    {
        visited[u] = true;
        vector<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            if (!visited[*i])
                dfs(visited, adj, s, *i);
        }
        s.push(u);
        return;
    }
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> s;
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(visited, adj, s, i);
        }
        vector<int> radj[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                radj[adj[i][j]].push_back(i);
            }
        }
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        int c = 0;
        while (!s.empty())
        {
            int t = s.top();
            s.pop();
            if (!visited[t])
            {
                dfs(visited, radj, s, t);
                c++;
            }
        }
        return c;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}