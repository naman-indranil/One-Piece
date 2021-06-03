#include <bits/stdc++.h>
using namespace std;
int kthelement(int a1[], int a2[], int n, int m, int k)
{
    int ind1 = 0, ind2 = 0;
    if (k == 0)
    {
        return -1;
    }

    while ((ind1 < n) && (ind2 < m) && (k > 0))
    {
        k--;
        if (k > 0)
        {
            if (a1[ind1] <= a2[ind2])
            {
                ind1++;
            }
            else if (a1[ind1] > a2[ind2])
            {
                ind2++;
            }
        }
        else if (k == 0)
        {
            if (a1[ind1] <= a2[ind2])
            {
                return a1[ind1];
            }
            else if (a1[ind1] > a2[ind2])
            {
                return a2[ind2];
            }
        }
    }
    if (ind1 < n && k > 0)
    {
        if ((ind1 + k - 1) < n)
            return a1[ind1 + k - 1];
    }
    else if (ind2 < m && k > 0)
    {
        if ((ind2 + k - 1) < m)
            return a2[ind2 + k - 1];
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    int a1[n];
    int a2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a2[i];
    }
    int k;
    cout << "enter kth:";
    cin >> k;
    cout << kthelement(a1, a2, n, m, k);
    return 0;
}