#include <bits/stdc++.h>
using namespace std;
typedef struct meet
{
    int st;
    int et;
} meet;

bool comp(meet a, meet b)
{
    if (a.et < b.et)
        return true;
    if (a.et == b.et)
        return a.st < b.st;
    return false;
}
void maxmeet(meet a[], int n)
{
    sort(a, a + n, comp);
    int c = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (c < a[i].st)
        {
            v.push_back(i);
            c = a[i].et;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << a[v[i]].st << "  " << a[v[i]].et << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << "enter meeting start and end times" << endl;
    meet a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].st;
        cin >> a[i].et;
    }
    maxmeet(a, n);
    return 0;
}