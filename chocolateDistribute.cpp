// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m);

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a;
        long long x;
        for (long long i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        long long m;
        cin >> m;
        cout << findMinDiff(a, n, m) << endl;
    }
    return 0;
} // } Driver Code Ends

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    //code
    long long diff, mindiff;
    sort(a.begin(), a.end());
    mindiff = a[n - 1];
    for (long long i = 0; i <= n - m; i++)
    {
        diff = a[i + m - 1] - a[i];
        if (mindiff > diff)
            mindiff = diff;
    }
    return mindiff;
}