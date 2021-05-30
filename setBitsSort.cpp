#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int bitsSet(int n)
    {
        int c = 0;
        while (n != 0)
        {
            if (n & 1)
            {
                c++;
            }
            n = n >> 1;
        }
        return c;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>> vec(32);
        int t;
        for (int i = 0; i < n; i++)
        {
            t = bitsSet(arr[i]);
            vec[t].push_back(arr[i]);
        }
        t = 0;
        for (int i = 31; i >= 0; i--)
        {
            vector<int> v = vec[i];
            for (int j = 0; j < v.size(); j++)
            {
                arr[t] = v[j];
                t++;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends