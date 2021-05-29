#include <bits/stdc++.h>
using namespace std;
void swap(vector<int> &nums,
          int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
int minSwaps(vector<int> &nums)
{
    // Code here
    vector<int> n = nums;
    map<int, int> h;
    int t;
    sort(n.begin(), n.end());
    int sw = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        h[nums[i]] = i;
    }
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] != nums[i])
        {
            sw++;
            t = nums[i];
            swap(nums, i, h[n[i]]);

            // Update the indexes in
            // the hashmap accordingly
            h[t] = h[n[i]];
            h[n[i]] = i;
        }
    }
    return sw;
}

int main()
{
    // Driver program to
    // test the above function
    vector<int> a = {101, 758, 315,
                     730, 472, 619,
                     460, 479};
    int n = a.size();

    // Output will be 5
    cout << minSwaps(a);
}