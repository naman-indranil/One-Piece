#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
} // } Driver Code Ends

// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int romanToDecimal(string str)
{
    // code here
    int res = 0;

    // Traverse given input
    for (int i = 0; i < str.length(); i++)
    {
        // Getting value of symbol s[i]
        char r = str[i];
        int s1 = -1;
        if (r == 'I')
            s1 = 1;
        if (r == 'V')
            s1 = 5;
        if (r == 'X')
            s1 = 10;
        if (r == 'L')
            s1 = 50;
        if (r == 'C')
            s1 = 100;
        if (r == 'D')
            s1 = 500;
        if (r == 'M')
            s1 = 1000;

        if (i + 1 < str.length())
        {
            // Getting value of symbol s[i+1]
            r = str[i + 1];
            int s2 = -1;
            if (r == 'I')
                s2 = 1;
            if (r == 'V')
                s2 = 5;
            if (r == 'X')
                s2 = 10;
            if (r == 'L')
                s2 = 50;
            if (r == 'C')
                s2 = 100;
            if (r == 'D')
                s2 = 500;
            if (r == 'M')
                s2 = 1000;
            // Comparing both values
            if (s1 >= s2)
            {
                // Value of current symbol
                // is greater or equal to
                // the next symbol
                res = res + s1;
            }
            else
            {
                // Value of current symbol is
                // less than the next symbol
                res = res + s2 - s1;
                i++;
            }
        }
        else
        {
            res = res + s1;
        }
    }
    return res;
}