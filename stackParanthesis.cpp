#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to check if brackets are balanced or not.
    int check(char c)
    {
        switch (c)
        {
        case '(':
            return -1;
        case ')':
            return 1;
        case '[':
            return -2;
        case ']':
            return 2;
        case '{':
            return -3;
        case '}':
            return 3;
        default:
            return 0;
        }
    }
    bool ispar(string x)
    {
        // Your code here
        stack<int> st;
        int l = x.length();
        int t;
        for (int i = 0; i < l; i++)
        {
            t = check(x[i]);
            if (t < 0)
            {
                st.push(t);
            }
            else
            {
                if (st.size() == 0)
                    return false;
                int n = st.top();
                if ((n + t) != 0)
                {
                    return false;
                }
                st.pop();
            }
        }
        if (st.size() > 0)
            return false;
        return true;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}