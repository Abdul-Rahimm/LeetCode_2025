class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size();

        vector<int> before;
        vector<int> after;
        int same = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
                before.push_back(nums[i]);
            else if (nums[i] > pivot)
                after.push_back(nums[i]);
            else
                same++;
        }

        // before already has the before elements
        // append to it rather than creating a new one

        while (same--)
            before.push_back(pivot);

        for (int i : after)
            before.push_back(i);

        return before;
    }
};