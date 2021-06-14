#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int checkMirrorTree(int n, int e, int A[], int B[])
    {
        // code here
        unordered_map<int, stack<int>> mp;
        for (int i = 0; i < e; i++)
        {
            mp[A[2 * i]].push(A[2 * i + 1]);
        }
        for (int i = 0; i < e; i++)
        {
            if (mp[B[2 * i]].top() != B[2 * i + 1])
            {
                return 0;
            }
            mp[B[2 * i]].pop();
        }
        return 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;

        cin >> n >> e;
        int A[2 * e], B[2 * e];

        for (int i = 0; i < 2 * e; i++)
            cin >> A[i];

        for (int i = 0; i < 2 * e; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n, e, A, B) << endl;
    }
    return 0;
} // } Driver Code Ends