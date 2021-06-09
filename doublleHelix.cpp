#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    n = 13;
    m = 11;
    // cin>>n;
    // cin>>m;
    int a[13] = {3, 5, 7, 9, 20, 25, 30, 40, 55, 56, 57, 60, 62};
    int b[11] = {1, 4, 7, 11, 14, 25, 44, 47, 55, 57, 100};
    vector<int> c;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            c.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << endl;
    for (i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }
    int s1[c.size() + 1] = {0};
    int s2[c.size() + 1] = {0};
    j = 0;
    for (i = 0; i < n; i++)
    {
        s1[j] += a[i];
        if (c[j] == a[i])
        {
            j++;
        }
    }
    j = 0;
    for (i = 0; i < m; i++)
    {
        s2[j] += b[i];
        if (c[j] == b[i])
        {
            j++;
        }
    }
    cout << endl;
    int maxs = 0;
    for (i = 0; i <= c.size(); i++)
    {
        cout << s1[i] << " " << s2[i] << endl;
        maxs += max(s1[i], s2[i]);
    }
    cout << "Max Sum:" << maxs;
    return 0;
}