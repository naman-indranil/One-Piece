#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPosition(int N)
    {
        // code here
        int pos = 0;
        int high = 0;
        int c = 1;
        int i = 1;
        if (!N)
        {
            return -1;
        }
        while (i <= N)
        {
            if (i & N)
            {
                high++;
                pos = c;
            }
            c++;
            i = i << 1;
        }
        if (high > 1)
            return -1;
        return pos;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}