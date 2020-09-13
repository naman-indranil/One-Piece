#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll a[101] = {0};
        ll temp, ansa = 0, ansb = 0;
        // memset(a, 0, sizeof(a));
        ll A[101] = {0}, B[101] = {0};
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            if (a[temp] == 0)
            {
                a[temp] += 1;
                A[temp] = 1;
            }
            else if (a[temp] > 0)
            {
                a[temp] += 1;
                B[temp] = 1;
            }
        }
        temp = 0;
        while (A[temp])
        {
            temp++;
            ansa = temp;
        }
        temp = 0;
        while (B[temp])
        {
            temp++;
            ansb = temp;
        }
        temp = ansa + ansb;
        cout << temp << endl;
    }
    return 0;
}
//
//
//