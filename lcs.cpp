#include <bits/stdc++.h>
using namespace std;
int ports(long int x[], long int y[], long int lx, long int ly)
{
    if (lx == 0 || ly == 0)
        return 0;
    if (x[lx - 1] == y[ly - 1])
    {
        return 1 + ports(x, y, lx - 1, ly - 1);
    }
    else
    {
        return max(ports(x, y, lx, ly - 1), ports(x, y, lx - 1, ly));
    }
}
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        long int lx;
        cin >> lx;
        long int x[lx];
        long int y[lx];
        for (long int i = 0; i < lx; i++)
            cin >> x[i];
        for (long int i = 0; i < lx; i++)
            cin >> y[i];
        cout << ports(x, y, lx, lx) << endl;
        t--;
    }
    return 0;
}

// This code is contributed by rathbhupendra
