#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

typedef struct ele
{
    long long int val;
    long long int ind;
} ele;

vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k)
{
    queue<long long int> q;
    queue<ele> st;
    long long int m = 0;
    long long int i;
    ele temp;
    for (i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            temp.val = a[i];
            temp.ind = i;
            st.push(temp);
        }
    }
    for (i = 0; i < n; i++)
    {
        temp.val = 0;
        temp.ind = -1;
        st.push(temp);
    }
    vector<long long int> vec;
    for (i = 0; i < n - k + 1; i++)
    {
        temp = st.front();
        if (temp.val == 0)
        {
            vec.push_back(0);
        }
        else
        {
            if (temp.ind < i)
            {
                while (st.front().val != 0 && st.front().ind < i)
                {
                    st.pop();
                }
            }
            temp = st.front();
            if (temp.val == 0)
            {
                vec.push_back(0);
            }
            else if (temp.ind < (i + k))
                vec.push_back(temp.val);
            else
                vec.push_back(0);
        }
    }

    return vec;
}