#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;
    int n, t;
    cin >> n;
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> t;
        a.push_back(t);
    }
    i = n - 1;
    t = 0;
    while (i >= 0)
    {
        if (a[i] > a[i - 1])
        {
            t = a[i - 1];
            a[i - 1] = a[i];
            a[i] = t;
            t = 1;
            break;
        }
        i--;
    }
    if (t == 0)
    {
        sort(a.begin(), a.end());
    }
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}