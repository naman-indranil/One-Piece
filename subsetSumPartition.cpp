#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int s = 0;
        for (int i = 0; i < n; i++)
            s = s + arr[i];
        if (s % 2 == 1)
            return 0;
        s = s / 2;
        bool dp[n + 1][s + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (i == 0 && j != 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= s; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][s];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}