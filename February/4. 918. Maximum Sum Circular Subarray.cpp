class Solution
{
public:
    int ans = INT_MIN;

    void DFS(int i, int count, int curr, vector<int> &nums)
    {
        int n = nums.size();

        if (i >= n or count == n / 2)
        {
            ans = max(ans, curr);
            return;
        }

        // check the current number
        DFS(i + 1, count + 1, curr + nums[i], nums);

        // if(nums[i%n] >= 0){
        //     return take;
        // }

        // nums[i] is negative. so you have three options
        DFS(INT_MAX, count, curr + nums[i], nums); // stop the process

        DFS(i + 1, 0, 0, nums);
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
            nums.push_back(nums[i]);

        int mx = -1e5;
        DFS(0, 0, mx, nums);

        return ans;
    }
};