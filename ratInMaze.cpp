#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    vector<string> ans;

    bool safe(int x, int y, int n)
    {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    void generate_paths(vector<vector<int>> &grid, vector<vector<bool>> &vis, string s, int x, int y)
    {
        int n = grid.size();

        if (grid[x][y] && x == n - 1 && y == n - 1)
        {
            ans.push_back(s);
            return;
        }
        vis[x][y] = true;

        int row[] = {-1, 0, 0, 1};
        int col[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++)
        {
            if (safe(x + row[k], y + col[k], n) && !vis[x + row[k]][y + col[k]] && grid[x + row[k]][y + col[k]])
            {
                if (row[k] == -1 && col[k] == 0)
                {
                    s += "U";
                }
                else if (row[k] == 0 && col[k] == -1)
                {
                    s += "L";
                }
                else if (row[k] == 0 && col[k] == 1)
                {
                    s += "R";
                }
                else
                {
                    s += "D";
                }
                generate_paths(grid, vis, s, x + row[k], y + col[k]);
                s.erase(s.size() - 1);
            }
        }
        vis[x][y] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n, int x = 0, int y = 0)
    {
        // Your code goes here
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        string s = "";
        if (m.size() && m[0][0])
            generate_paths(m, vis, s, 0, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}