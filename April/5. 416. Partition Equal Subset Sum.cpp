class Solution
{
public:
    int dp[201][20001];
    bool solve(int i, vector<int> &nums, int totalSum, int currSum)
    {

        if (i >= nums.size())
        {
            return dp[i][currSum] = (currSum * 2 == totalSum);
        }
        if (dp[i][currSum] != -1)
            return dp[i][currSum];

        bool take = solve(i + 1, nums, totalSum, currSum + nums[i]);
        bool nott = solve(i + 1, nums, totalSum, currSum);

        return dp[i][currSum] = take || nott;
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        memset(dp, -1, sizeof(dp));

        bool status = solve(0, nums, totalSum, 0);

        return status;
    }
};