#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        int n1 = 0, n2 = 0;
        int c = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            c ^= nums[i];
        }
        c = c & (~(c - 1));
        for (int i = 0; i < nums.size(); i++)
        {
            if (c & nums[i])
            {
                n1 ^= nums[i];
            }
            else
            {
                n2 ^= nums[i];
            }
        }
        vector<int> v;
        if (n1 > n2)
        {
            v.push_back(n2);
            v.push_back(n1);
        }
        else
        {
            v.push_back(n1);
            v.push_back(n2);
        }
        return v;
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
        vector<int> v(2 * n + 2);
        for (int i = 0; i < 2 * n + 2; i++)
            cin >> v[i];
        Solution ob;
        vector<int> ans = ob.singleNumber(v);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}