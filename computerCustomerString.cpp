#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ch[256] = {0};
    int c = 0;
    int us = 0;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        if (c < n)
        {
            if (ch[s[i]] == 0)
            {
                c++;
                ch[s[i]] = 1;
            }
            else if (ch[s[i]] == 1)
            {
                c--;
                ch[s[i]] = 0;
            }
        }
        else if (c == n)
        {
            if (ch[s[i]] == 1)
            {
                c--;
                ch[s[i]] = 0;
            }
            else if (ch[s[i]] == 0)
            {
                us++;
            }
        }
    }
    cout << (us / 2) << endl;
}