#include <bits/stdc++.h>
using namespace std;
class Stack
{
    int top;

public:
    int a[10001];
    Stack()
    {
        top = -1;
    }
    bool push(int d)
    {
        if (top > 10000)
        {
            return false;
        }
        a[++top] = d;
        return true;
    }
    int pop()
    {
        if (top == -1)
        {
            return -1;
        }
        return a[top--];
    }
    bool empty()
    {
        return (top == -1);
    }
    int peek()
    {
        if (top < 0)
        {
            return -1;
        }
        return a[top];
    }
};
int main()
{
    class Stack st;
    for (int i = 1; i < 10; i++)
        st.push(i);
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << st.pop() << " ";
    }
    cout << endl
         << st.peek() << endl;
    cout << st.empty();
    return 0;
}