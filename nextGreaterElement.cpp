#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here
        stack<long long> s;
        unordered_map<long long, long long> mp;
        s.push(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if (s.size() == 0)
                s.push(arr[i]);
            else
            {
                while (s.size() > 0 && s.top() < arr[i])
                {
                    mp[s.top()] = arr[i];
                    s.pop();
                }
                s.push(arr[i]);
            }
        }
        while (s.size() > 0)
        {
            mp[s.top()] = -1;
            s.pop();
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = mp[arr[i]];
        }
        return arr;
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
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}