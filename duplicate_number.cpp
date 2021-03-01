#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &num)
{
    sort(num.begin(), num.end());
    int j = num.size();
    int t = num[0];
    for (int i = 1; i < j; i++)
    {
        if (t == num[i])
            return t;
        else
        {
            t = num[i];
        }
    }
}
int main()
{
    vector<int> num;
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        num.push_back(t);
    }
    cout << findDuplicate(num);
    return 0;
}