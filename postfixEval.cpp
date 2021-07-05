#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to evaluate a postfix expression.
    static int isNum(char ch)
    {
        if (ch >= '0' && ch <= '9')
            return 1;
        return 0;
    }
    static int solve(char ch, int a, int b)
    {
        switch (ch)
        {
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        case '*':
            return (a * b);
        case '/':
            return (a / b);
        }
    }
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        int l = S.length();
        int val = 0;
        int t;
        for (int i = 0; i < l; i++)
        {
            if (isNum(S[i]))
            {
                t = (S[i] - '0');
                st.push(t);
            }
            else
            {
                t = st.top();
                st.pop();
                val = solve(S[i], st.top(), t);
                st.pop();
                st.push(val);
            }
        }
        val = st.top();
        return val;
    }
};
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;

        cout << obj.evaluatePostfix(S) << endl;
    }
    return 0;
}