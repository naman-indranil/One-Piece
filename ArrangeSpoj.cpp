#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[100000], n, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);

        int j = 0;
        while (a[j] == 1)
        {
            printf("1 ");
            j++;
        }

        if (j == n - 2 && a[j] == 2 && a[j + 1] == 3)
            printf("2 3");
        else
        {
            for (int k = n - 1; k >= j; k--)
                printf("%d ", a[k]);
        }

        printf("\n");
    }
    return 0;
}