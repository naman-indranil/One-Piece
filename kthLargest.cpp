#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "enter k:\n";
    int k;
    cin >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    cout << "\n Ans:";
    cout << pq.top();
    return 0;
}