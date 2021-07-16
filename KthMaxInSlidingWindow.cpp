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
    int k;
    cout << "enter k:\n";
    cin >> k;
    for (int i = 0; i <= n - k; i++)
    {
        priority_queue<int> pq;
        for (int j = i; j < i + k; j++)
        {
            pq.push(a[j]);
        }
        cout << pq.top() << " ";
    }
    return 0;
}