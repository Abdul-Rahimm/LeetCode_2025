class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ops = 0;

        for (int i = 0; i < n - 2; i++)
        {

            if (nums[i] == 0)
            {
                nums[i] = 1;
                nums[i + 1] = nums[i + 1] == 1 ? 0 : 1;
                nums[i + 2] = nums[i + 2] == 1 ? 0 : 1;
                ops++;
            }
        }

        return nums[n - 1] == 1 and nums[n - 2] == 1 ? ops : -1;
    }
};