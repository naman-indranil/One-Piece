
#include <bits/stdc++.h>
using namespace std;

int minsubarray(int arr[], int n, int k)
{

    int wsum = 0;
    int minw = INT_MAX;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        wsum += arr[i];
        if (i + 1 >= k)
        {
            if (minw > wsum)
            {
                minw = wsum;
                l = i;
            }
            wsum -= arr[i + 1 - k];
        }
    }
    int s = 0;
    for (int j = l - k + 1; j <= l; j++)
        s = s + arr[j];
    return s;
}
int maxsubarray(int arr[], int n, int k)
{
    int wsum = 0;
    int maxw = INT_MIN;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        wsum += arr[i];
        if (i + 1 >= k)
        {
            if (maxw < wsum)
            {
                maxw = wsum;
                l = i;
            }
            wsum -= arr[i + 1 - k];
        }
    }
    int s = 0;
    for (int j = l - k + 1; j <= l; j++)
        s = s + arr[j];
    return s;
}
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n;
        cin >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << maxsubarray(arr, n, k) << "," << minsubarray(arr, n, k) << endl;
        t--;
    }
    return 0;
}