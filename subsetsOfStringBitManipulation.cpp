#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {
        int l = s.length();
        unsigned int pow_set_size = pow(2, l);
        int counter, j;
        vector<string> subs;
        int ind = 0;
        /*Run from counter 000..0 to 111..1*/
        for (counter = 0; counter < pow_set_size; counter++)
        {
            subs.push_back("");
            for (j = 0; j < l; j++)
            {
                /* Check if jth bit in the counter is set
            If set then print jth element from set */
                if (counter & (1 << j))
                    subs[ind] += s[j];
            }
            ind++;
        }
        sort(subs.begin(), subs.end());
        vector<string> v(subs.size() - 1);
        copy(subs.begin() + 1, subs.end(), v.begin());
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}