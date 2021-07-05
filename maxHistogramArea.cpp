#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long hist[], int n)
    {
        stack<long long> s;
        long long max_area = 0;
        long long tp;
        long long area_with_top;
        long long i = 0;
        while (i < n)
        {
            if (s.empty() || hist[s.top()] <= hist[i])
                s.push(i++);

            else
            {
                tp = s.top();
                s.pop();
                area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

                if (max_area < area_with_top)
                    max_area = area_with_top;
            }
        }

        while (s.empty() == false)
        {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }

        return max_area;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}