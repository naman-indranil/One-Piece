#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// return the smallest window in S with all the characters of P
// if no such window exists, return "-1"

#define MAX_CHARS 256
class Solution
{
public:
    string smallestWindow(string str, string pat)
    {
        // Your code here
        int len1 = str.length();
        int len2 = pat.length();

        // Check if string's length
        // is less than pattern's
        // length. If yes then no such
        // window can exist
        if (len1 < len2)
        {
            cout << "-1";
            return "";
        }

        int hash_pat[256] = {0};
        int hash_str[256] = {0};

        // Store occurrence ofs characters
        // of pattern
        for (int i = 0; i < len2; i++)
            hash_pat[pat[i]]++;

        int start = 0, start_index = -1, min_len = INT_MAX;

        // Start traversing the string
        // Count of characters
        int count = 0;
        for (int j = 0; j < len1; j++)
        {

            // Count occurrence of characters
            // of string
            hash_str[str[j]]++;

            // If string's char matches with
            // pattern's char
            // then increment count
            if (hash_str[str[j]] <= hash_pat[str[j]])
                count++;

            // if all the characters are matched
            if (count == len2)
            {

                // Try to minimize the window
                while (hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0)
                {

                    if (hash_str[str[start]] > hash_pat[str[start]])
                        hash_str[str[start]]--;
                    start++;
                }

                // update window size
                int len_window = j - start + 1;
                if (min_len > len_window)
                {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }

        // If no window found
        if (start_index == -1)
        {
            cout << "-1";
            return "";
        }

        // Return substring starting from start_index
        // and length min_len
        return str.substr(start_index, min_len);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
} // } Driver Cod