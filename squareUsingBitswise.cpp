#include <bits/stdc++.h>
using namespace std;
int findSquare(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int x = n >> 1;
    if (n & 1)
    {
        return ((findSquare(x) << 2) + (x << 2) + 1);
    }
    else
    {
        return (findSquare(x) << 2);
    }
}
int main()
{
    int n;
    cin >> n;
    n = abs(n);
    cout << findSquare(n);
    return 0;
}