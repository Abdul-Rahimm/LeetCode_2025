class Solution
{
public:
    map<vector<int>, int> mp;
    void allSubsets(int i, vector<int> &nums, vector<int> curr, vector<vector<int>> &ans)
    {
        if (i >= nums.size())
        {

            sort(curr.begin(), curr.end());
            if (mp.find(curr) == mp.end())
            {
                ans.push_back(curr);
            }
            mp[curr]++;
            return;
        }

        curr.push_back(nums[i]);
        allSubsets(i + 1, nums, curr, ans);
        curr.pop_back();
        allSubsets(i + 1, nums, curr, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;

        vector<int> curr;
        allSubsets(0, nums, curr, ans);

        return ans;
    }
};