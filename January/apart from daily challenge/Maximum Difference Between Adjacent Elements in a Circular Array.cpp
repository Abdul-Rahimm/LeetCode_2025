class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        int n = nums.size();
        int mx = 0;

        for (int i = 0; i < n - 1; i++)
        {
            mx = max(mx, abs(nums[i] - nums[i + 1]));
        }

        mx = max(mx, abs(nums[n - 1] - nums[0]));

        return mx;
    }
};