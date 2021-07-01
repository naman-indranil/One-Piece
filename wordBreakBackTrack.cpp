#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<string> res;
    int dictionaryContains(string word, vector<string> &dict)
    {

        int size = dict.size();
        for (int i = 0; i < size; i++)
            if (dict[i].compare(word) == 0)
                return true;
        return false;
    }
    void wordBreakUtil(string str, int n, string result, vector<string> &dict)
    {
        //Process all prefixes one by one
        for (int i = 1; i <= n; i++)
        {
            // Extract substring from 0 to i in prefix
            string prefix = str.substr(0, i);

            // If dictionary conatins this prefix, then
            // we ignore this prefix (there is no else for
            // this if) and try next
            if (dictionaryContains(prefix, dict))
            {
                // If no more elements are there, print it
                if (i == n)
                {
                    // Add this element to previous prefix
                    result += prefix;
                    res.push_back(result);
                    return;
                }
                wordBreakUtil(str.substr(i, n - i), n - i, result + prefix + " ", dict);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string> &dict, string str)
    {
        // code here
        wordBreakUtil(str, str.size(), "", dict);
        //  sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<string> dict;
        string s;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;

        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
    }
    return 0;
}