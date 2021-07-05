#include <bits/stdc++.h>
using namespace std;
void insertBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }
    int y = st.top();
    st.pop();
    insertBottom(st, x);
    st.push(y);
}
void reverse(stack<int> &st)
{
    if (!st.empty())
    {
        int x = st.top();
        st.pop();
        reverse(st);
        insertBottom(st, x);
    }
}
int main()
{
    stack<int> st;
    for (int i = 1; i < 10; i++)
        st.push(i);
    reverse(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}