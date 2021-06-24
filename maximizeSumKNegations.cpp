#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long int maximizeSum(long long int arr[], int n, int k)
    {
        long long int sum = 0;
        int i = 0;

        sort(arr, arr + n);
        while (k > 0)
        {
            if (arr[i] >= 0)
                break;
            else
            {
                arr[i] = (-1) * arr[i];
                k = k - 1;
            }
            i++;
        }
        sort(arr, arr + n);
        while (k > 0)
        {
            arr[0] = -arr[0];
            k--;
        }
        for (int j = 0; j < n; j++)
        {
            sum += arr[j];
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximizeSum(a, n, k) << endl;
    }

    return 0;
}