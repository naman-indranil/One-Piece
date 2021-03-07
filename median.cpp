#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
public:
    int find_median(vector<int> v)
    {
        // Code here.
        sort(v.begin(), v.end());
        int size = v.size();
        if (size % 2 == 1)
            return (v[size / 2]);
        else
        {
            int sum = v[size / 2 - 1] + v[size / 2];
            return sum / 2;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        Solution ob;
        int ans = ob.find_median(v);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends