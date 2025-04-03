class Solution
{
public:
    int sumOfBeauties(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> before(n), after(n);

        before[0] = nums[0];
        after[n - 1] = nums[n - 1];

        for (int i = 1, j = n - 2; i < n; i++, j--)
        {
            before[i] = max(before[i - 1], nums[i]);
            after[j] = min(after[j + 1], nums[j]);
        }

        int ans = 0;

        for (int i = 1; i < n - 1; i++)
        {

            if (nums[i] > before[i - 1] and nums[i] < after[i + 1])
                ans += 2;
            else if (nums[i] > nums[i - 1] and nums[i] < nums[i + 1])
                ans++;
        }

        return ans;
    }
};