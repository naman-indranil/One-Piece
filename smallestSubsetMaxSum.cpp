#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int lh = 0;
    int rh = 0;
    int rs = 0;
    rh = arr[n - 1];
    rs = 1;
    for (int i = 0; i < n - 1; i++)
    {
        lh += arr[i];
    }
    int i = n - 2;
    while (lh > rh && i >= 0)
    {
        lh -= arr[i];
        rh += arr[i];
        rs++;
        i--;
    }
    cout << "Subset Length:" << rs << endl;
    return 0;
}