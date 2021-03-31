#include <bits/stdc++.h>
using namespace std;
void solveWordWrap(int arr[], int n, int k)
{
    int i, j;
    // Variable to store number of
    // characters in given line.
    int currlen;
    // Variable to store possible
    // minimum cost of line.
    int cost;
    // DP table in which dp[i] represents
    // cost of line starting with word
    // arr[i].
    int dp[n];
    // Array in which ans[i] store index
    // of last word in line starting with
    // word arr[i].
    int ans[n];
    // If only one word is present then
    // only one line is required. Cost
    // of last line is zero. Hence cost
    // of this line is zero. Ending point
    // is also n-1 as single word is
    // present.
    dp[n - 1] = 0;
    ans[n - 1] = n - 1;
    // Make each word first word of line
    // by iterating over each index in arr.
    for (i = n - 2; i >= 0; i--)
    {
        currlen = -1;
        dp[i] = INT_MAX;
        // Keep on adding words in current
        // line by iterating from starting
        // word upto last word in arr.
        for (j = i; j < n; j++)
        {
            // Update number of characters
            // in current line. arr[j] is
            // number of characters in
            // current word and 1
            // represents space character
            // between two words.
            currlen += (arr[j] + 1);
            // If limit of characters
            // is violated then no more
            // words can be added to
            // current line.
            if (currlen > k)
                break;
            // If current word that is
            // added to line is last
            // word of arr then current
            // line is last line. Cost of
            // last line is 0. Else cost
            // is square of extra spaces
            // plus cost of putting line
            // breaks in rest of words
            // from j+1 to n-1.
            if (j == n - 1)
                cost = 0;
            else
                cost = (k - currlen) * (k - currlen) + dp[j + 1];
            // Check if this arrangement gives
            // minimum cost for line starting
            // with word arr[i].
            if (cost < dp[i])
            {
                dp[i] = cost;
                ans[i] = j;
            }
        }
    }
    // Print starting index and ending index
    // of words present in each line.
    i = 0;
    while (i < n)
    {
        cout << i + 1 << " " << ans[i] + 1 << " ";
        i = ans[i] + 1;
    }
    cout << endl;
}

// Driver function
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        t--;
        int n, l;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> l;
        solveWordWrap(arr, n, l);
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while (t > 0)
//     {
//         t--;
//         int n, l;
//         cin >> n;
//         int ar[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> ar[i];
//         }
//         cin >> l;
//         int dp[n][l];
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < l; j++)
//             {
//                 dp[i][j] = 0;
//             }
//         }
//         int r = 0, c = 0;
//         int w = 1;
//         for (int i = 0; i < n; i++)
//         {
//             if ((l - c - 1) >= ar[i])
//             {

//                 for (int j = c; j <= c + ar[i]; j++)
//                 {
//                     dp[r][j] = w;
//                 }
//                 w++;
//                 c = c + ar[i] + 1;
//             }
//             else
//             {
//                 r++;
//                 c = 0;
//             }
//         }
//         int temp = 1;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < l; j++)
//             {
//                 // if (dp[i][j] == temp && dp[i][j] != 0)
//                 // {
//                 cout << dp[i][j];
//                 //     temp++;
//                 // }
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
//     return 0;
// }