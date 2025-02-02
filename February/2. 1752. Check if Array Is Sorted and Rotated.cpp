class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int index;
        int mn = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= mn)
            {
                mn = nums[i];
                index = i;

                while (i + 1 < n and nums[i + 1] == mn)
                    i++;
            }
        }

        for (int i = 0; i < n; i++)
            nums.push_back(nums[i]);

        for (int i = index; i < n + index - 1; i++)
        {
            cout << nums[i] << " ";
            if (nums[i + 1] - nums[i] < 0)
                return false;
        }

        return true;
    }
};