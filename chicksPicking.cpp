#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, b, t;
    cout << "enter number of chicks:";
    cin >> n;
    cout << endl
         << "enter number required in barn:";
    cin >> k;
    cout << endl
         << "enter barn dist:";
    cin >> b;
    cout << endl
         << "enter time deadline:";
    cin >> t;
    int pos[n] = {0};
    cout << "enter chicks  start pos:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> pos[i];
    }
    int v[n] = {0};
    cout << "enter chicks speed" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int rt[n];
    for (int i = 0; i < n; i++)
    {
        rt[i] = ceil((b - pos[i]) * 1.0 / v[i]);
    }
    int carry = 0;
    int swaps[n] = {0};
    for (int i = n - 1; i >= 0; i--)
    {
        if (rt[i] > t)
            carry++;
        else
        {
            swaps[i] = carry;
            k--;
        }
    }
    if (k > 0)
        cout << "IMPOSSIBLE";
    else
    {
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << swaps[i] << " ";
    }
    return 0;
}