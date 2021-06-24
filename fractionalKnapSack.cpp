#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends

class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(struct Item a, struct Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, cmp);
        int curWeight = 0;       // Current weight in knapsack
        double finalvalue = 0.0; // Result (value in Knapsack)

        // Looping through all Items
        for (int i = 0; i < n; i++)
        {
            // If adding Item won't overflow, add it completely
            if (curWeight + arr[i].weight <= W)
            {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }

            // If we can't add current Item, add fractional part
            // of it
            else
            {
                int remain = W - curWeight;
                finalvalue += arr[i].value * ((double)remain / (double)arr[i].weight);
                break;
            }
        }

        // Returning final value
        return finalvalue;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    //taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        //size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        //value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        //function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}