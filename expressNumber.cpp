#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    long long int arr[16];
    arr[0] = 1;
    arr[1] = 2;
    for (int i = 2; i <= 15; i++)
    {
        arr[i] = arr[i - 1] * 2 * 2;
    }
    while (t--)
    {
        long long int n;
        long long int x;
        cin >> n;
        cin >> x;
        int k = 0;
        if (n == x)
        {
            cout << "1" << endl;
            continue;
        }
        int i = 15;
        while (n > 0)
        {
            if (n <= x)
            {
                n = n - x;
                k++;
            }
            else if (i > 0)
            {
                if (arr[i] <= n)
                {
                    k++;
                    n = n - arr[i];
                }
                else
                {
                    i--;
                }
            }
            else if (i <= 0 && x == 0)
            {
                k = -1;
                break;
            }
        }
        cout << k << endl;
    }
    return 0;
}