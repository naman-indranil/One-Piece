class Solution
{
public:
    void dfs(bool visited[], list<int> adj[], int u)
    {
        visited[u] = true;
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            if (!visited[*i])
                dfs(visited, adj, *i);
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int cable = connections.size();
        if (cable < n - 1)
            return -1;
        bool *visited = new bool[n];
        for (int i = 0; i < n; i++)
            visited[i] = false;
        int clust = 0;
        list<int> adj[n];
        for (int i = 0; i < cable; i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                clust++;
                dfs(visited, adj, i);
            }
        }
        if (clust == 1)
            return 0;
        return clust - 1;
    }
};