class Solution
{
public:
    string reorganizeString(string s)
    {
        int n = s.size();
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;

        for (auto it : mp)
        {
            if (it.second > (n + 1) / 2)
                return "";
        }

        priority_queue<pair<int, char>> pq;
        for (auto it : mp)
            pq.push({it.second, it.first});

        string ans = "";
        while (pq.size() > 1)
        {
            pair<int, char> p1 = pq.top();
            pq.pop();
            pair<int, char> p2 = pq.top();
            pq.pop();

            ans = ans + p1.second + p2.second;

            if (mp[p1.second] > 1)
            {
                mp[p1.second]--;
                pq.push({mp[p1.second], p1.second});
            }
            if (mp[p2.second] > 1)
            {
                mp[p2.second]--;
                pq.push({mp[p2.second], p2.second});
            }
        }

        if (pq.size() == 1)
        {
            ans += pq.top().second;
            pq.pop();
        }

        return ans;
    }
};