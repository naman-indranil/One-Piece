#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends

string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_set<int> a;
    unordered_set<int> b;
    for (int i = 0; i < n; i++)
    {
        a.insert(a1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        b.insert(a2[i]);
    }
    int la, lb;
    la = a.size();
    lb = b.size();
    int na;
    for (int i = 0; i < m; i++)
    {
        a.insert(a2[i]);
    }
    na = a.size();
    if (na == la)
        return "Yes";
    else
        return "No";
}