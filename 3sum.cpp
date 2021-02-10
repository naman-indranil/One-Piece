#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int num[n] = {0};
    int v;
    int ts[n][n - 1];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    if (n >= 3)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    ts[i][j] = num[i] + num[j];
                }
            }
        }
        for (int k = 0; k < n; k++)
        {
            v = -num[k];
            for (int i = 0; i < n / 2; i++)
            {
                if (i == k)
                {
                }
                else
                {
                    for (int j = 0; j < n / 2; j++)
                    {
                        if (v == ts[i][j])
                        {
                            cout << num[k] << num[i] << num[j] << endl;
                        }
                    }
                }
            }
        }
    }
}