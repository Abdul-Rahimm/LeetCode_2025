class Solution
{
public:
    int ans = 0;

    void solve(vector<int> &curr, int i, vector<int> &nums)
    {
        if (i >= nums.size())
        {
            // ans.push_back(curr);
            int add = curr.size() == 0 ? 0 : curr[0];

            for (int i = 1; i < curr.size(); i++)
                add ^= curr[i];

            ans += add;
            return;
        }

        curr.push_back(nums[i]);
        solve(curr, i + 1, nums);
        curr.pop_back();
        solve(curr, i + 1, nums);
    }

    int subsetXORSum(vector<int> &nums)
    {
        vector<int> current;

        solve(current, 0, nums);

        return ans;
    }
};