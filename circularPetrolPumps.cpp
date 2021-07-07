#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution
{
public:
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        int s = 0, e = 1;
        int cp = p[0].petrol - p[0].distance;
        while (s != e || cp < 0)
        {
            while (cp < 0 && s != e)
            {
                cp -= p[s].petrol - p[s].distance;
                s = (s + 1) % n;
                if (s == 0)
                    return -1;
            }
            cp += p[e].petrol - p[e].distance;
            e = (e + 1) % n;
        }

        return s;
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
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        Solution obj;
        cout << obj.tour(p, n) << endl;
    }
}