#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
} // } Driver Code Ends

//User function Template for C++

//Function to reverse first k elements of a queue.

queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    if (k <= 1)
        return q;
    int t;
    stack<int> st;
    while (k > 0)
    {
        k--;
        t = q.front();
        st.push(t);
        q.pop();
    }
    queue<int> q2;
    while (!st.empty())
    {
        t = st.top();
        st.pop();
        q2.push(t);
    }
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        q2.push(t);
    }
    return q2;
}