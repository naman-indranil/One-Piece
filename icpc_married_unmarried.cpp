#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string st;
        cin >> st;
        int l = st.length();
        if (l <= 1)
            cout << "No" << endl;
        auto f = st.find("MU");
        if (f < l)
        {
            cout << "Yes" << endl;
        }
        else
        {
            char curr;
            char prev;
            char next;
            for (int i = 1; i < l - 1; i++)
            {
                prev = st[i - 1];
                curr = st[i];
                next = st[i + 1];
                if (curr == '?' && prev == 'M')
                {
                    int j = i + 1;
                    while (st[j] == '?' && j < l)
                    {
                        j++;
                    }
                    if (j >= l)
                    {
                        break;
                    }
                    else if (st[j] == 'U' && prev == 'M')
                    {
                        cout << "Yes" << endl;
                        curr = 'Y';
                        break;
                    }
                }
            }
            if (curr != 'Y')
                cout << "No";
        }
    }
    return 0;
}