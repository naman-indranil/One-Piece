#include <bits/stdc++.h>
using namespace std;
int findpivot(int arr[], int l, int h, int key)
{
    int mid;
    if (h == 0)
    {
        return 0;
    }
    while (l <= h)
    {
        mid = l + (h - l) / 2;
        if (arr[mid] == key)
        {
            return arr[mid];
        }
        else if (arr[mid] > key)
        {
            l = mid + 1;
        }
        else if (arr[mid] < key)
        {
            h = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int t = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        t = max(t, arr[i]);
    }
    cout << findpivot(arr, 0, n - 1, t);
    return 0;
}