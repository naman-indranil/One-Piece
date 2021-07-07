#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    stack<int> st;
    for (int i = 1; i <= 20; i++)
        q.push(i);
    int t = q.size();
    t = t / 2;
    for (int i = 0; i < t; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < t; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < t; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < t; i++)
    {
        st.push(q.front());
        q.pop();
    }
    int a, b;
    for (int i = 0; i < t; i++)
    {
        a = q.front();
        b = st.top();
        q.pop();
        st.pop();
        q.push(a);
        q.push(b);
    }
    for (int i = 0; i < 20; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}