#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, k;
    cin >> n;
    int a[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter search:";
    cin >> x;
    cout << "Enter step:";
    cin >> k;
    int s = 0;
    s = a[0];
    int j = 0;
    for (int i = 0; i < n;)
    {
        s = a[i];
        if (s == x)
        {
            cout << "Index:" << i << endl;
            break;
        }
        i += max(1, abs(x - s) / k);
    }
    return 0;
}