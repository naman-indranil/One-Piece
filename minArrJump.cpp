#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int minJumps(int arr[], int n)
{

    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;
    int i = 1;
    for (i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jump;
        maxReach = max(maxReach, i + arr[i]);
        // we use a step to get to the current index
        step--;
        if (step == 0)
        {
            jump++;
            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if (i >= maxReach)
                return -1;
            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }
    return -1;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << minJumps(arr, n) << endl;
    }
    return 0;
}