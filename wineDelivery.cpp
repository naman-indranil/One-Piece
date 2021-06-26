#include <bits/stdc++.h>
using namespace std;
struct wine
{
    int am;
    int ind;
};
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cost = 0;
    list<pair<int, int>> buy;
    list<pair<int, int>> sell;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            buy.push_back(make_pair(a[i], i));
        }
        else
        {
            sell.push_back(make_pair(-a[i], i));
        }
    }
    while (!buy.empty() && !sell.empty())
    {
        pair<int, int> b = buy.front();
        pair<int, int> s = sell.front();
        cout << b.first << " " << s.first << endl;
        if (b.first < s.first)
        {
            cost += b.first * abs((s.second - b.second));
            buy.pop_front();
            sell.pop_front();
            // pair<int, int> t = {s.first - b.first, s.second};
            int t = abs(s.first - b.first);
            sell.push_front(make_pair(t, s.second));
        }
        else if (b.first > s.first)
        {
            cost += s.first * abs((s.second - b.second));
            buy.pop_front();
            sell.pop_front();
            int t = abs(s.first - b.first);
            buy.push_front(make_pair(t, b.second));
        }
        else
        {
            cost += s.first * abs((s.second - b.second));
            buy.pop_front();
            sell.pop_front();
        }
    }
    cout << endl
         << cost << " is the cost";
    return 0;
}