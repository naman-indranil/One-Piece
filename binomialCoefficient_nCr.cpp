#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define p 1000000007;
class Solution
{
public:
    int nCr(int n, int r)
    {
        if (n < r)
            return 0;
        if (n == r || r == 0)
            return 1;
        if (r == 1)
            return n;

        int r1[n + 1] = {0};
        int r2[n + 1] = {0};
        r1[0] = 1;
        r2[0] = 1;
        r2[1] = 1;
        int in1 = 0, in2 = 0, f = 0;
        for (int i = 2; i <= n; i++)
        {
            if (f == 0)
            {
                int j;
                r1[0] = r2[0];
                r1[i] = r2[i - 1];
                for (j = 1; j < i; j++)
                {
                    r1[j] = (r2[j] + r2[j - 1]) % p;
                }
                f = 1;
            }
            else
            {
                int j;
                r2[0] = r1[0];
                r2[i] = r1[i - 1];
                for (j = 1; j < i; j++)
                {
                    r2[j] = (r1[j] + r1[j - 1]) % p;
                }
                f = 0;
            }
        }
        if (n % 2 == 1)
            return r2[r];
        else
            return r1[r];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
}