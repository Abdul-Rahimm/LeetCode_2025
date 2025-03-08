class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        unordered_map<int, int> mp;
        int n = grid.size();

        for (auto row : grid)
        {
            for (int i : row)
            {
                mp[i]++;
            }
        }

        vector<int> ans(2);
        for (int i = 1; i <= n * n; i++)
        {
            if (mp.find(i) == mp.end())
                ans[1] = i;
            else if (mp[i] == 2)
                ans[0] = i;
        }

        return ans;
    }
};