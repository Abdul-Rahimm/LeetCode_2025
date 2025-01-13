class Solution
{
public:
    vector<int> zigzagTraversal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> nums;

        for (int i = 0; i < n; i++)
        {

            if (i % 2 == 0)
                for (int j = 0; j < m; j++)
                {
                    nums.push_back(grid[i][j]);
                }

            if (i % 2 != 0)
                for (int j = m - 1; j >= 0; j--)
                {
                    nums.push_back(grid[i][j]);
                }
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i += 2)
        {
            ans.push_back(nums[i]);
        }

        return ans;
    }
};