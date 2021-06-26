#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (long long i = 0; i < n; i++)
            pq.push(arr[i]);
        long long cost = 0;
        long long len = 0;
        while (pq.size() > 1)
        {
            len = 0;
            len = pq.top();
            pq.pop();
            len += pq.top();
            pq.pop();
            pq.push(len);
            cost = cost + len;
        }
        return cost;
    }
};

// { Driver Code Starts.
long long minCost(long long arr[], long long n);
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}