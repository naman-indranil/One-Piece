// C++Program to count islands in boolean 2D matrix
#include <bits/stdc++.h>
using namespace std;

// A utility function to do DFS for a 2D
// boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void DFS(vector<vector<int>> &M, int i, int j, int ROW,
         int COL)
{
    //Base condition
    //if i less than 0 or j less than 0 or i greater than ROW-1 or j greater than COL- or if M[i][j] != 1 then we will simply return
    if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1) || M[i][j] != 1)
    {
        return;
    }

    if (M[i][j] == 1)
    {
        M[i][j] = 0;
        DFS(M, i + 1, j, ROW, COL);     //right side traversal
        DFS(M, i - 1, j, ROW, COL);     //left side traversal
        DFS(M, i, j + 1, ROW, COL);     //upward side traversal
        DFS(M, i, j - 1, ROW, COL);     //downward side traversal
        DFS(M, i + 1, j + 1, ROW, COL); //upward-right side traversal
        DFS(M, i - 1, j - 1, ROW, COL); //downward-left side traversal
        DFS(M, i + 1, j - 1, ROW, COL); //downward-right side traversal
        DFS(M, i - 1, j + 1, ROW, COL); //upward-left side traversal
    }
}

int countIslands(vector<vector<int>> &M)
{
    int ROW = M.size();
    int COL = M[0].size();
    int count = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (M[i][j] == 1)
            {
                M[i][j] = 0;
                count++;
                DFS(M, i + 1, j, ROW, COL);     //right side traversal
                DFS(M, i - 1, j, ROW, COL);     //left side traversal
                DFS(M, i, j + 1, ROW, COL);     //upward side traversal
                DFS(M, i, j - 1, ROW, COL);     //downward side traversal
                DFS(M, i + 1, j + 1, ROW, COL); //upward-right side traversal
                DFS(M, i - 1, j - 1, ROW, COL); //downward-left side traversal
                DFS(M, i + 1, j - 1, ROW, COL); //downward-right side traversal
                DFS(M, i - 1, j + 1, ROW, COL); //upward-left side traversal
            }
        }
    }
    return count;
}

// Driver Code
int main()
{
    vector<vector<int>> M = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};

    cout << "Number of islands is: " << countIslands(M);
    return 0;
}

// This code is contributed by ajaymakvana.

// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends

// class Solution
// {
// public:
//     //Function to find the number of islands.
//     bool isValid(int dx, int dy, vector<vector<char>> grid)
//     {
//         int l1 = grid.size();
//         int l2 = grid[0].size();
//         if (dx >= 0 && dx < l1 && dy >= 0 && dy < l2)
//             return true;
//         return false;
//     }
//     void dfs(vector<vector<bool>> &visited, int x, int y, vector<vector<char>> grid, int a[], int b[])
//     {
//         visited[x][y] = true;
//         for (int i = 0; i < 7; i++)
//         {
//             if (isValid(x + a[i], y + b[i], grid) == false)
//                 continue;
//             if (grid[x + a[i]][y + b[i]] == '0')
//                 continue;
//             if (visited[x + a[i]][y + b[i]] == false)
//                 dfs(visited, x + a[i], y + b[i], grid, a, b);
//         }
//         return;
//     }
//     int numIslands(vector<vector<char>> &grid)
//     {
//         int h = grid.size();
//         int w = grid[0].size();
//         vector<vector<bool>> visited(h, vector<bool>(w, false));
//         vector<pair<int, int>> xy;
//         for (int i = 0; i < h; i++)
//         {
//             for (int j = 0; j < w; j++)
//             {
//                 if (grid[i][j] == '1')
//                     xy.push_back({i, j});
//             }
//         }
//         int a[] = {-1, -1, -1, 0, 0, 1, 1, 1};
//         int b[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//         int clust = 0;
//         int l = xy.size();
//         for (int i = 0; i < l; i++)
//         {
//             pair<int, int> t = xy[i];
//             if (visited[t.first][t.second] == false)
//             {
//                 clust++;
//                 dfs(visited, t.first, t.second, grid, a, b);
//             }
//         }
//         return clust;
//     }
// };

// // { Driver Code Starts.
// int main()
// {
//     int tc;
//     cin >> tc;
//     while (tc--)
//     {
//         int n, m;
//         cin >> n >> m;
//         vector<vector<char>> grid(n, vector<char>(m, '#'));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 cin >> grid[i][j];
//             }
//         }
//         Solution obj;
//         int ans = obj.numIslands(grid);
//         cout << ans << '\n';
//     }
//     return 0;
// }