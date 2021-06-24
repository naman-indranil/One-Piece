#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s, n, m;
    cin >> s;
    cin >> n;
    cin >> m;
    if (n < m)
    {
        cout << "Cant survive" << endl;
    }
    else if (s >= 7 && 6 * n < 7 * m)
    {
        cout << "Can't survive" << endl;
    }
    else
    {
        int d = 0, c = 0;
        while (c < m * s)
        {
            d++;
            c = c + n;
        }
        cout << d << " Days" << endl;
    }
    return 0;
}