// C++ implementation of the approach
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

// Function that returns true if it is possible
// to rearrange the characters of the string
// such that no two consecutive characters are same
int isPossible(string str)
{

    // To store the frequency of
    // each of the character
    unordered_map<char, int> freq;

    // To store the maximum frequency so far
    int max_freq = 0;
    for (int j = 0; j < (str.length()); j++)
    {
        freq[str[j]]++;
        if (freq[str[j]] > max_freq)
            max_freq = freq[str[j]];
    }

    // If possible
    if (max_freq <= (str.length() - max_freq + 1))
        return true;
    return false;
}

// Driver code
int main()
{
    string str = "geeksforgeeks";

    if (isPossible(str))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
