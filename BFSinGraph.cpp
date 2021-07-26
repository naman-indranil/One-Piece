#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> v;
        queue<int> q;
        q.push(0);
        bool visited[V] = {false};
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            if (!visited[t])
            {
                v.push_back(t);
                visited[t] = true;
            }
            int l = adj[t].size();
            for (int i = 0; i < l; i++)
            {
                if (visited[adj[t][i]] == false)
                    q.push(adj[t][i]);
            }
        }
        return v;
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
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}