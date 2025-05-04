class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        map<pair<int, int>, int> mp;

        for (vector<int> i : dominoes)
        {
            sort(i.begin(), i.end());
            int a = i[0];
            int b = i[1];

            mp[{a, b}]++;
        }

        int ans = 0;
        for (auto row : mp)
        {
            int freq = row.second;

            ans += ((freq - 1) * (freq)) / 2;
        }

        return ans;
    }
};