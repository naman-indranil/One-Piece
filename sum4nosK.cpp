#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int y)
    {
        // Your code goes here
        map<int, int> h;
        int s = 0;
        int ind = 0;
        int l = arr.size();
        // sort(arr.begin(), arr.end());
        unordered_set<int> St;
        for (int i = 0; i < l; i++)
        {
            h[arr[i]] = i;
            St.insert(arr[i]);
        }
        vector<int> vec;
        unordered_set<int>::iterator si;
        for (si = St.begin(); si != St.end(); si++)
        {
            vec.push_back(*si);
        }
        l = vec.size();
        sort(vec.begin(), vec.end());
        for (int i = 0; i < l; i++)
        {
            h[vec[i]] = i;
            cout << vec[i] << " ";
        }
        vector<vector<int>> quad;
        vector<int> temp;
        for (int i = 0; i < l; i++)
        {
            for (int j = i + 1; j < l; j++)
            {
                for (int k = j + 1; k < l; k++)
                {
                    s = y - (vec[i] + vec[j] + vec[k]);
                    if (h[s] >= 0)
                    {
                        if (h[s] < k)
                        {
                            if (h[s] < j)
                            {
                                if (h[s] < i)
                                {
                                    temp.push_back(vec[h[s]]);
                                    temp.push_back(vec[i]);
                                }

                                else
                                {
                                    temp.push_back(vec[i]);
                                    temp.push_back(vec[h[s]]);
                                }
                                temp.push_back(vec[j]);
                            }
                            else
                            {
                                temp.push_back(vec[j]);
                                temp.push_back(vec[h[s]]);
                            }
                        }

                        temp.push_back(vec[k]);

                        quad.push_back(temp);
                        temp.clear();
                    }
                    if (s < 0)
                    {
                        k = l;
                    }
                }
            }
        }
        return quad;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends