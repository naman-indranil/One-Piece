#include <iostream>
#include <string.h>

using namespace std;
#define MAX_CHARS 256

class Solution
{
public:
    // This function returns true if str1 and str2 are ismorphic
    // else returns false
    bool areIsomorphic(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();

        // Length of both strings must be
        // same for one to one
        // corresponance
        if (n != m)
            return false;

        // For counting the previous appearences of character in
        // both the strings
        int count[MAX_CHARS] = {0};
        int dcount[MAX_CHARS] = {0};

        // Process all characters one by one
        for (int i = 0; i < n; i++)
        {
            count[str1[i]]++;
            dcount[str2[i]]++;

            // For string to be isomorphic the previous counts
            // of appearences of
            // current character in both string must be same if
            // it is not same we return false.
            if (count[str1[i]] != dcount[str2[i]])
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin >> t;
    string s1, s2;
    while (t--)
    {
        cin >> s1;
        cin >> s2;
        Solution obj;
        cout << obj.areIsomorphic(s1, s2) << endl;
    }

    return 0;
}