#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution
{
public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a, Job b)
    {
        if (a.profit > b.profit)
            return true;
        else if (a.profit == b.profit)
            return (a.dead > b.dead);
        return false;
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        int maxd = 0;
        for (int i = 0; i < n; i++)
        {
            if (maxd < arr[i].dead)
            {
                maxd = arr[i].dead;
            }
        }
        // cout<<maxd<<endl;
        int slot[maxd + 1] = {0};
        sort(arr, arr + n, comp);
        vector<int> v;
        int maxp = 0;
        int jobs = 0;

        int j = 0;
        for (int i = 0; i < n; i++)
        {

            if (slot[arr[i].dead] == 0)
            {
                maxp += arr[i].profit;
                jobs++;
                slot[arr[i].dead] = 1;
            }
            else
            {
                for (j = min(arr[i].dead, maxd); j > 0; j--)
                {
                    if (slot[j] == 0)
                        break;
                }
                if (slot[j] == 0 && j > 0)
                {
                    maxp += arr[i].profit;
                    jobs++;
                    slot[j] = 1;
                }
            }
        }
        v.push_back(jobs);
        v.push_back(maxp);
        return v;
    }
};

// { Driver Code Starts.
// Driver program to test methods
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
        Job arr[n];

        //adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}