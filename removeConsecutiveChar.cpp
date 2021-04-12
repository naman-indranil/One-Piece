#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string removeConsecutiveCharacter(string s)
    {

        char ch = s[0];
        int l = s.length();
        string st = "";

        st = st + s[0];
        for (int i = 1; i < l; i++)
        {
            if (ch != s[i])
            {
                st = st + s[i];
                ch = s[i];
            }
        }
        return st;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeConsecutiveCharacter(s) << endl;
    }
}

// } Driver Code Ends