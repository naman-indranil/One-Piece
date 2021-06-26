#include <bits/stdc++.h>

using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void QuickSort(int *A, int Left, int Right)
{
    int i = Left, j = Right;
    int pivot = A[(Left + Right) / 2];
    /* partition */
    while (i <= j)
    {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i <= j)
        {
            Swap(A[i], A[j]);
            i++;
            j--;
        }
    }

    /* recursion */
    if (Left < j)
        QuickSort(A, Left, j);
    if (i < Right)
        QuickSort(A, i, Right);
}

int main()
{
    int t;
    int w, h, n;
    int finalRs, tempMaxX, tempMaxY;
    int x[40002];
    int y[40002];
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        cin >> w;
        cin >> h;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
            cin >> y[i];
        }
        x[0] = 0;
        x[n + 1] = w + 1;
        y[0] = 0;
        y[n + 1] = h + 1;
        QuickSort(x, 0, n + 1);
        QuickSort(y, 0, n + 1);

        tempMaxX = 0;
        for (int i = 1; i <= n + 1; i++)
            tempMaxX = max(tempMaxX, x[i] - x[i - 1] - 1);

        tempMaxY = 0;
        for (int i = 1; i <= n + 1; i++)
            tempMaxY = max(tempMaxY, y[i] - y[i - 1] - 1);

        finalRs = tempMaxX * tempMaxY;
        cout << finalRs << "\n";
    }
}