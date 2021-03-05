#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Complete this function
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int> sum;
        int s = 0, l1, l2;
        for (int i = 0; i < n; i++)
        {
            s = s + arr[i];
            if (s == 0)
                return true;
            else
            {
                l1 = sum.size();
                sum.insert(s);
                l2 = sum.size();
                if (l1 == l2)
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
// Driver code
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
            cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
} // } Driver Code Ends