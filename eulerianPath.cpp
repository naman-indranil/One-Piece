#include <bits/stdc++.h>
using namespace std;
void eulerian(vector<vector<int>> adj, int n)
{
    unordered_map<int, int> edgec;
    for (int i = 0; i < n; i++)
    {
        int g = 0;
        for (int j = 0; j < n; j++)
        {
            g = g + adj[i][j];
        }
        edgec[i] = g;
    }
    if (!adj.size())
        return;
    for (int i = 0; i < n; i++)
    {
        stack<int> currp;
        vector<int> path;
        currp.push(i);
        int currv = i;
        while (!currp.empty())
        {
            if (edgec[currv])
            {
                currp.push(currv);
                int next = adj[currv].back();
                edgec[currv]--;
                adj[currv].pop_back();
                currv = next;
            }
            else
            {
                path.push_back(currv);
                currv = currp.top();
                currp.pop();
            }
        }
        for (int j = path.size() - 1; j >= 0; j--)
        {
            cout << path[j] << "--->";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> adj;
    int n;
    cin >> n;
    int x;
    cout << "enter adj matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> t;
        cout << "neighbors of" << i << ":" << endl;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            t.push_back(x);
        }
        adj.push_back(t);
    }
    eulerian(adj, n);
}