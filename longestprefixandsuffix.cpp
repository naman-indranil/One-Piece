// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int lps(string str)
    {
        // Your code goes here
        int n = str.length();

        // if n is less than 2
        if (n < 2)
        {
            return 0;
        }

        int len = 0;
        int i = 1;

        // Iterate i till n
        while (i < n)
        {

            // If str[i] is equal to
            // str[len]
            if (str[i] == str[len])
            {
                ++len;
                ++i;
            }
            else
            {
                i = i - len + 1;
                len = 0;
            }
        }

        // Return len
        return len;
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
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
} // } Driver Code Ends