#include <bits/stdc++.h>
using namespace std;
int gcd(int m, int n)
{
    if (n == 0)
        return m;
    return gcd(n, m % n);
}
int pour(int fromjug, int tojug, int d)
{
    int to = 0, from = 0;
    int steps = 1;
    from = fromjug;
    while (from != d && to != d)
    {
        int t = min(from, tojug - to);
        to += t;
        from -= t;
        steps++;
        if (from == d || to == d)
            return steps;
        if (from == 0)
            from = fromjug, steps++;
        if (to == tojug)
            to = 0, steps++;
    }
    return steps;
}
int minSteps(int m, int n, int d)
{
    if (m > n)
        swap(m, n);
    if (d > n)
        return -1;
    if (d % (gcd(n, m)) != 0)
        return -1;
    return min(pour(m, n, d), pour(n, m, d));
}
int main()
{
    int n = 3, m = 5, d = 4;

    printf("Minimum number of steps required is %d",
           minSteps(m, n, d));

    return 0;
}