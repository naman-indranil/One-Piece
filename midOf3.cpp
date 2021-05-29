#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int middle(int A, int B, int C)
    {
        //code here//Position this line where user code will be pasted.
        if (A > B)
        {
            if (B > C)
            {
                return B;
            }
            return C;
        }
        else if (A < B)
        {
            if (B < C)
                return B;
            else if (A < C)
                return C;
            return A;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        Solution ob;
        cout << ob.middle(A, B, C) << "\n";
    }
    return 0;
} // } Driver Code Ends