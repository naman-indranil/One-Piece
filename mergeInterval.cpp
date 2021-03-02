#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> a;
    vector<int> r;
    int n, t, p, q;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        r.push_back(t);
        cin >> t;
        r.push_back(t);
        a.push_back(r);
        r.clear();
    }
    sort(a.begin(), a.end());
    t = a[0][1];
    p = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i][0] <= t)
        {
            a[p][1] = a[i][1];
            t = a[i][1];
            // a.erase(a.begin() + i);
            a[i][1] = -1;
        }

        else
        {
            p++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i][1] >= 0)
            cout << a[i][0] << " " << a[i][1] << endl;
    }
    return 0;
}

//
//
// sort(intervals.begin(), intervals.end());

//         vector<vector<int>> merged;
//         for (auto interval : intervals) {
//             // if the list of merged intervals is empty or if the current
//             // interval does not overlap with the previous, simply append it.
//             if (merged.empty() || merged.back()[1] < interval[0]) {
//                 merged.push_back(interval);
//             }
//             // otherwise, there is overlap, so we merge the current and previous
//             // intervals.
//             else {
//                 merged.back()[1] = max(merged.back()[1], interval[1]);
//             }
//         }
//         return merged;