#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    if (a.first == b.first)
        return a.second < b.second;
    return false;
}
int main()
{
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    cout << "enter intervals" << endl;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), comp);
    cout << "intervals sorted:\n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    vector<pair<int, int>> vec;
    int j = 0;
    vec.push_back(make_pair(v[0].first, v[0].second));
    for (int i = 1; i < n; i++)
    {
        if (v[i].first <= vec[j].second)
        {
            vec[j].second = v[i].second;
        }
        else
        {
            vec.push_back(make_pair(v[i].first, v[i].second));
            j++;
        }
    }
    cout << "Merged Interval:\n";
    for (int i = 0; i <= j; i++)
    {
        cout << vec[i].first << " " << vec[i].second << endl;
    }
    return 0;
}