#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1 = "XY";
    string s2 = "12";
    string s = "X12Y";
    int i = 0, j = 0, k = 0;
    if (s1.length() + s2.length() != s.length())
    {
        cout << "no shuffle" << endl;
    }
    else
    {
        while (k != s.length())
        {
            if (s1.at(i) == s.at(k))
            {
                i++;
            }
            else if (s2.at(j) == s.at(k))
            {
                j++;
            }
            k++;
        }
        if (i + j == k)
        {
            cout << "shuffle" << endl;
        }
        else
        {
            cout << "no shuffle" << endl;
        }
    }
    return 0;
}