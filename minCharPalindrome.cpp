#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l = s.length();
    string st;
    int br = 0;
    int flag = 0;
    int j = 0;
    int t;
    for (int i = l - 1; i >= 0; i--)
    {
        flag = 0;
        j = 0;
        t = i;
        for (; j <= t; j++, t--)
        {

            if (s[j] != s[t])
            {
                br = t;
                flag = 1;
                break;
            }
        }
        if (j > i / 2 && flag != 1)
        {
            break;
        }
    }
    st = s.substr(br, l);
    reverse(st.begin(), st.end());
    cout << s << endl;
    cout << st << endl;
    return 0;
}