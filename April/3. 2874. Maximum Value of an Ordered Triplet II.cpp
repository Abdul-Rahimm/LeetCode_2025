class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> before(n), after(n);

        for (int i = 1; i < n; i++)
        {
            before[i] = max(before[i - 1], nums[i - 1]);
            after[n - i - 1] = max(after[n - i], nums[n - i]);
        }

        long long ans = 0;

        for (int i = 1; i < n - 1; i++)
        {
            ans = max(ans, (long long)(before[i] - nums[i]) * after[i]);
        }

        return ans;
    }
};