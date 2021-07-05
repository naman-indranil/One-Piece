#include <iostream>
#include <stack>
using namespace std;
void push(stack<int> &s, int a);
bool isFull(stack<int> &s, int n);
bool isEmpty(stack<int> &s);
int pop(stack<int> &s);
int getMin(stack<int> &s);
stack<int> s;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n;
        while (!isEmpty(s))
        {
            pop(s);
        }
        while (!isFull(s, n))
        {
            cin >> a;
            push(s, a);
        }
        cout << getMin(s) << endl;
    }
} // } Driver Code Ends

stack<int> mn;
void push(stack<int> &s, int a)
{
    // Your code goes here
    if (s.empty())
        mn.push(a);
    else
        mn.push(min(mn.top(), a));
    s.push(a);
}

bool isFull(stack<int> &s, int n)
{
    // Your code goes here
    if (s.size() >= n)
        return 1;
    return 0;
}

bool isEmpty(stack<int> &s)
{
    // Your code goes here
    if (s.size() == 0)
        return 1;
    return 0;
}

int pop(stack<int> &s)
{
    // Your code goes here
    int x = s.top();
    mn.pop();
    s.pop();
    return x;
}

int getMin(stack<int> &s)
{
    // Your code goes here
    return mn.top();
}