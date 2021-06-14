#include <bits/stdc++.h>
using namespace std;
void inorder(int a[], vector<int> &v, int n, int i)
{
    if (i >= n)
    {
        return;
    }
    inorder(a, v, n, 2 * i + 1);
    v.push_back(a[i]);
    inorder(a, v, n, 2 * i + 2);
}
int minSwaps(vector<int> &v)
{
    vector<pair<int, int>> vec(v.size());
    int swaps = 0;
    for (int i = 0; i < v.size(); i++)
    {
        vec[i].first = v[i];
        vec[i].second = i;
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == vec[i].second)
        {
            continue;
        }
        else
        {
            swap(vec[i].first, vec[vec[i].second].first);
            swap(vec[i].second, vec[vec[i].second].second);
            swaps++;
        }
        if (vec[i].second != i)
            --i;
    }
    return swaps;
}

int main()
{
    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}