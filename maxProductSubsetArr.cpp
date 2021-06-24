#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int max_neg = INT_MIN;
    int count_neg = 0, count_zero = 0;
    int prod = 1;
    for (int i = 0; i < n; i++)
    {

        // If number is 0, we don't
        // multiply it with product.
        if (a[i] == 0)
        {
            count_zero++;
            continue;
        }

        // Count negatives and keep
        // track of negative number
        // with least absolute value
        if (a[i] < 0)
        {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }

        prod = prod * a[i];
    }

    // If there are all zeros
    if (count_zero == n)
        return 0;

    // If there are odd number of
    // negative numbers
    if (count_neg & 1)
    {

        // Exceptional case: There is only
        // negative and all other are zeros
        if (count_neg == 1 &&
            count_zero > 0 &&
            count_zero + count_neg == n)
            return 0;

        // Otherwise result is product of
        // all non-zeros divided by
        //negative number with
        // least absolute value
        prod = prod / max_neg;
    }

    cout << prod;
    return 0;
}