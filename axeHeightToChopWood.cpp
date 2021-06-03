#include <bits/stdc++.h>
using namespace std;
int getwood(int h, int a[], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (h < a[i])
        {
            c += a[i] - h;
        }
    }
    return c;
}
int height(int a[], int n, int w)
{
    sort(a, a + n);
    int l = a[0], h = a[n - 1];
    int k = 0;

    int mid;
    while (l < h)
    {
        mid = l + (h - l) / 2;
        k = getwood(mid, a, n);
        if (k >= w && getwood(mid + 1, a, n) < w)
        {
            return mid;
        }
        if (k >= w)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return 0;
}
int main()
{
    int n, w;
    cin >> n;
    cin >> w;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Axe height: " << height(a, n, w);
    return 0;
}