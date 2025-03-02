class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        map<int, int> mp;

        for (auto row : nums1)
        {
            mp[row[0]] = row[1];
        }

        for (auto row : nums2)
        {
            mp[row[0]] += row[1];
        }

        vector<vector<int>> ans;

        for (auto row : mp)
        {
            vector<int> curr{row.first, row.second};
            ans.push_back(curr);
        }

        return ans;
    }
};