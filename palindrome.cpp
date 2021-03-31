#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int isPlaindrome(string S)
    {
        // Your code goes here

        string r = "";
        string::reverse_iterator i;
        for (i = S.rbegin(); i != S.rend(); i++)
        {
            r = r + *i;
        }
        if (S.compare(r) == 0)
        {
            return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.isPlaindrome(s) << "\n";
    }

    return 0;
} // } Driver Code Ends