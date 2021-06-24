#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if (a.second < b.second)
            return true;
        else if (a.second == b.second)
            return (a.first < b.first);
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> m;
        for (int i = 0; i < n; i++)
        {
            m.push_back(make_pair(start[i], end[i]));
        }
        sort(m.begin(), m.end(), comp);
        int mp = 0;
        int endt = -1;
        for (int i = 0; i < n; i++)
        {
            if (endt < m[i].first)
            {
                mp++;
                endt = m[i].second;
            }
        }
        return mp;
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
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}