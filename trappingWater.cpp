// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    int min(int a, int b)
    {
        if (a < b)
            return a;
        return b;
    }
    int trappingWater(int bars[], int n)
    {
        int water = 0;

        // `left[i]` stores the maximum height of a bar to the left
        // of the current bar
        int left[n - 1];
        left[0] = INT_MIN;

        // process bars from left to right
        for (int i = 1; i < n - 1; i++)
        {
            left[i] = max(left[i - 1], bars[i - 1]);
        }

        /*
    int right[n];
    right[n - 1] = INT_MIN;
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i+1], bars[i+1]);
    }
 
    for (int i = 1; i < n - 1; i++)
    {
        if (min(left[i], right[i]) > bars[i]) {
            water += min(left[i], right[i]) - bars[i];
        }
    }
    */

        // `right` stores the maximum height of a bar to the right
        // of the current bar
        int right = INT_MIN;

        // process bars from right to left
        for (int i = n - 2; i >= 1; i--)
        {
            right = max(right, bars[i + 1]);

            // check if it is possible to store water in the current bar
            if (min(left[i], right) > bars[i])
            {
                water += min(left[i], right) - bars[i];
            }
        }

        return water;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}