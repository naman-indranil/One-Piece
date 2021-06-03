#include <bits/stdc++.h>
using namespace std;
int check(int a[], int mid, int n, int c)
{
    int cow = 1, pos = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] - pos >= mid)
        {
            pos = a[i];
            cow++;
        }
        if (cow == c)
        {
            return 1;
        }
    }
    return 0;
}
int placecow(int a[], int n, int c)
{
    sort(a, a + n);
    int l = a[0], h = a[n - 1];
    int mid;
    int mind = -1;
    while (l < h)
    {
        mid = l + (h - l) / 2;
        if (check(a, mid, n, c) == 1)
        {
            mind = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return mind;
}
int main()
{
    int n, c;
    cin >> n;
    cin >> c;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << placecow(a, n, c);
    return 0;
}