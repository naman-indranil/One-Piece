#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "ABC";
    int l = s.length();
    for (int i = 0; i <= l; i++)
    {
        cout << s[i] << endl;
        if (s[i] == '\0')
            cout << "1" << endl;
    }
    return 0;
}