#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int count(int S[], int m, int n)
    {

        //code here.
        long long int table[n + 1][m];
        for (int i = 0; i < m; i++)
            table[0][i] = 1;

        // Fill rest of the table entries
        // in bottom up manner
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Count of solutions including S[j]
                long long int x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;

                // Count of solutions excluding S[j]
                long long int y = (j >= 1) ? table[i][j - 1] : 0;

                // total count
                table[i][j] = x + y;
            }
        }
        return table[n][m - 1];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}