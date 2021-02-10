#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int doUnion(int a[], int n, int b[], int m);
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int c = 0;
    c = doUnion(a, n, b, m);
    cout << c << endl;
    return 0;
}
int doUnion(int a[], int n, int b[], int m)
{
    int l = n + m;
    int d[l];
    for (int i = 0; i < n; i++)
    {
        d[i] = a[i];
    }
    for (int i = n; i < l; i++)
    {
        d[i] = b[i - n];
    }
    sort(d, d + l);
    for (int i = 0; i < l; i++)
    {
        cout << d[i] << " ";
    }
    m = 0;
    for (int i = 0; i < l; i++)
    {

        if (i == 0)
        {
            m++;
            n = d[i];
        }
        else
        {
            if (n == d[i])
                continue;

            else if (n != d[i])
            {
                m++;
                n = d[i];
            }
        }
    }
    return m;
}