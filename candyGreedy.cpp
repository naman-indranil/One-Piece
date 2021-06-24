#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        sort(candies, candies + n);
        int mina = 0;
        int maxa = 0;
        int l = n;
        for (int i = 0; i < l; i++)
        {
            mina += candies[i];
            l = l - k;
        }
        l = 0;
        for (int i = n - 1; i >= l; i--)
        {
            maxa += candies[i];
            l = l + k;
        }
        vector<int> v;
        v.push_back(mina);
        v.push_back(maxa);
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
} // } Driver Code Ends