#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    string::reverse_iterator i;
    for (i = s.rbegin(); i != s.rend(); i++)
        cout << *i;
    return 0;
}