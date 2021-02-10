#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main()
{
    ll int t, n, match;
    cin >> t;
    while (t--)
    {
        cin >> n;

        char a[n];
        ll int i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // while (match > 0)
        // {
        //     d = match % 10;
        //     a[i] = d;
        //     i--;
        //     match = match / 10;
        // }
        ll int l = n;
        ll int Revenc = 0, Boddc = 0;
        ll int Roddc = 0, Bevenc = 0;
        for (i = 0; i < n; i++)
        {
            if ((i + 1) % 2 != 0)
            {
                if ((int)a[i] % 2 == 0)
                {
                    Revenc += 1;
                }
                if ((int)a[i] % 2 != 0)
                {
                    Roddc += 1;
                }
            }
            else
            {
                if ((int)a[i] % 2 != 0)
                {
                    Boddc += 1;
                }
                if ((int)a[i] % 2 == 0)
                {
                    Bevenc += 1;
                }
            }
        }

        ll int rt = 0, bt = 0;
        rt = Revenc + Roddc;
        bt = Bevenc + Boddc;
        if (rt > bt)
        {
            if (Roddc >0)
                cout << "1" << endl;
            else
            {
                cout << "2" << endl;
            }
        }
        else
        {
            if (Bevenc > 0)
                cout << "2" << endl;
            else
                cout << "1" << endl;
        }
    }
    return 0;
}