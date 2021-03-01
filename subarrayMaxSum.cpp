// kadane algo
#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum(int arr[], int n);
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s = 0;
    s = maxSubarraySum(arr, n);
    cout << s;
    return 0;
}
int maxSubarraySum(int arr[], int n)
{
    int s = 0, t;
    int max = 0;
    for (t = 0; t < n; t++)
    {
        s = s + arr[t];
        if (s > max)
        {
            max = s;
        }
        else if (s < 0)
        {
            s = 0;
        }
    }
    return max;
}
