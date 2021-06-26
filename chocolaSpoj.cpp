#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    m--;
    n--;
    int w[n];
    int l[m];
    int hor = 1;
    int ver = 1;
    int cost = 0;
    cout << "enter width costs" << endl;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    cout << "enter length costs" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> l[i];
    }
    int i = 0, j = 0;
    sort(w, w + n, greater<int>());
    sort(l, l + m, greater<int>());
    while (i < n && j < m)
    {
        if (w[i] > l[j])
        {
            ver++;
            cost += w[i] * hor;
            i++;
        }
        else if (w[i] < l[j])
        {
            hor++;
            cost += l[j] * ver;
            j++;
        }
        else if (w[i] == l[j])
        {
            if (hor >= ver)
            {
                cost += l[j] * ver;
                hor++;
                j++;
            }
            else
            {
                cost += w[i] * hor;
                i++;
                ver++;
            }
        }
    }
    if (i < n)
    {
        for (; i < n; i++)
            cost += w[i] * hor;
    }
    if (j < m)
    {
        for (; j < m; j++)
            cost += l[j] * ver;
    }
    cout << endl
         << "Cost: " << cost;
    return 0;
}