class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxL = 1;
        int last_chosen_index = 0;

        vector<int> dp(n, 1);
        vector<int> prev_idx(n, -1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {

                if (nums[i] % nums[j] == 0)
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j;
                    }
                }

                if (dp[i] > maxL)
                {
                    maxL = dp[i];
                    last_chosen_index = i;
                }
            }
        }

        vector<int> ans;
        while (last_chosen_index != -1)
        {
            ans.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }

        return ans;
    }
};