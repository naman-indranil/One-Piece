#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int l, h, t;
    cin >> n;
    l = 0;
    h = n - 1;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0 && a[h] < 0)
        {
            t = a[h];
            a[h] = a[i];
            h--;
            a[i] = t;
        }
        else if (a[i] < 0 && a[l] >= 0)
        {
            t = a[l];
            a[l] = a[i];
            l++;
            a[i] = t;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}