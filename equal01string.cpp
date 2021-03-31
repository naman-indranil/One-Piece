#include <bits/stdc++.h>
#include <string>
using namespace std;
int equal01(string st)
{
    int c = 0;
    int n0 = 0;
    int n1 = 0;
    string::iterator i;
    for (i = st.begin(); i != st.end(); i++)
    {
        if (*i == '1')
        {
            n1++;
        }
        else if (*i == '0')
        {
            n0++;
        }
        if (n1 == n0)
        {
            c++;
        }
    }
    return c;
}
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        string st;
        cin >> st;
        cout << equal01(st) << endl;
        t--;
    }
    return 0;
}