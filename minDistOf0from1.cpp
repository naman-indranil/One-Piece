#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find distance of nearest 1 in the grid for each cell.
    typedef struct ele
    {
        int x;
        int y;
    } ele;
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        vector<ele> zero;
        vector<ele> one;
        ele temp;
        int n = grid.size();
        int mm = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < mm; j++)
            {
                temp.x = j;
                temp.y = i;
                if (grid[i][j] == 1)
                {
                    one.push_back(temp);
                }
                else
                {
                    zero.push_back(temp);
                }
            }
        }
        vector<int> near;
        int m = INT_MAX;
        for (int i = 0; i < zero.size(); i++)
        {
            temp = zero[i];
            m = INT_MAX;
            for (int j = 0; j < one.size(); j++)
            {
                m = min(m, abs(temp.x - one[j].x) + abs(temp.y - one[j].y));
            }
            near.push_back(m);
        }
        vector<vector<int>> vec;
        vector<int> row;
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            row.clear();
            for (int j = 0; j < mm; j++)
            {
                if (grid[i][j] == 1)
                {
                    row.push_back(0);
                }
                else
                {
                    row.push_back(near[l]);
                    l++;
                }
            }
            vec.push_back(row);
        }
        return vec;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}