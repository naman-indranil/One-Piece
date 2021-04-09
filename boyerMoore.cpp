#include <bits/stdc++.h>
using namespace std;

void search(string txt, string pat);
void badCharHeuristic(string str, int size, int badchar[256])
{
    int i;
    for (i = 0; i < 256; i++)
    {
        badchar[i] = -1;
    }
    for (i = 0; i < size; i++)
    {
        badchar[(int)str[i]] = i;
    }
}
int main()
{
    string s;
    string t;
    cin >> s;
    cin >> t;
    search(s, t);
    return 0;
}
void search(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
    int badchar[256];
    badCharHeuristic(pat, m, badchar);
    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
        {
            j--;
        }
        if (j < 0)
        {
            cout << s << endl;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else
        {
            s += max(1, j - badchar[txt[s + j]]);
        }
    }
}