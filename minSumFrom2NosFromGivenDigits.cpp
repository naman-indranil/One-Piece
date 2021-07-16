#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    string solve(int arr[], int n)
    {
        // code here
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        string n1 = "";
        string n2 = "";
        int flag = 0;
        while (pq.size() > 0)
        {
            if (flag == 0)
            {
                n1 = to_string(pq.top()) + n1;
                flag = 1;
                pq.pop();
            }
            else if (flag == 1)
            {
                n2 = to_string(pq.top()) + n2;
                flag = 0;
                pq.pop();
            }
        }
        // cout<<n1<<endl<<n2;
        string res = "";
        int l1 = n1.length();
        int l2 = n2.length();
        int c = 0;
        int i, j;
        int t;
        char a, b;
        for (i = l1 - 1, j = l2 - 1; i >= 0 && j >= 0; i--, j--)
        {
            a = n1[i];
            b = n2[j];
            t = (a - '0') + (b - '0') + c;
            c = t / 10;
            t = t % 10;
            res = to_string(t) + res;
        }
        while (i >= 0)
        {
            a = n1[i];
            t = (a - '0') + c;
            c = t / 10;
            t = t % 10;
            res = to_string(t) + res;
            i--;
        }
        while (j >= 0)
        {
            b = n2[j];
            t = (b - '0') + c;
            c = t / 10;
            t = t % 10;
            res = to_string(t) + res;
            j--;
        }
        if (c > 0)
        {
            res = to_string(c) + res;
        }
        const regex pattern("^0+(?!$)");

        res = regex_replace(res, pattern, "");
        return res;
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
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}