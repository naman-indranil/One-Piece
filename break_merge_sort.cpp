#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr[n];
        int temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            cin >> temp1;
            while (temp1--)
            {
                cin >> temp2;
                arr[i].push_back(temp2);
            }
        }
        for (int i = 0; i < n; i++)
        {
            sort(arr[i].begin(), arr[i].end());
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({arr[i][0], i});
        }
        vector<int> res;
        int l = 0;
        int cost = 0;
        while (!pq.empty())
        {
            pair<int, int> top1 = pq.top();
            pq.pop();
            int tp = top1.first;
            pair<int, int> top2 = pq.top();
            int j;
            for (j = 0; j < arr[top1.second].size(); j++)
            {
                if (arr[top1.second][j] > tp)
                {
                    j--;
                    break;
                }
            }
            int k = j;
            while (arr[top1.second][k] <= top2.first)
            {
                k++;
            }
            j = min(k - j, (int)arr[top1.second].size() - 1 - k);
            pq.push({arr[top1.second][k], top1.second});
        }
        cout << cost << endl;
    }
    return 0;
}