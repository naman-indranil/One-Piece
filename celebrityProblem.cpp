#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &m, int n)
    {
        // code here
        int c = 0;
        stack<int> st;
        for (int i = 0; i < n; i++)
            st.push(i);
        int a, b;
        while (st.size() > 1)
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            if (m[b][a] == 1)
            {
                st.push(a);
            }
            else
            {
                st.push(b);
            }
        }
        if (st.size() == 0)
            return -1;
        c = st.top();
        st.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == c)
                continue;
            if (m[i][c] == 0 || m[c][i] == 1)
                return -1;
        }
        return c;
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}