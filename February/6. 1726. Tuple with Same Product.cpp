class Solution
{
public:
    int dp[1001][1001];
    vector<vector<int>> tuples;

    int DFS(vector<int> &nums, int i, int j)
    {

        if (j - i + 1 < 4)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int score = 0;

        if (nums[i] * nums[j] == nums[i + 1] * nums[j - 1])
        {
            score += 8;
            tuples.push_back({nums[i], nums[i + 1], nums[j - 1], nums[j]});
        }

        if (j - i + 1 == 4)
            return dp[i][j] = score;

        int inc = DFS(nums, i + 1, j);
        int dec = DFS(nums, i, j - 1);
        // int both = DFS(nums, i + 1, j - 1);

        score += inc + dec;
        // score += inc + dec + both;

        return dp[i][j] = score;
    }

    int tupleSameProduct(vector<int> &nums)
    {
        int i = 0;
        int j = nums.size() - 1;
        memset(dp, -1, sizeof(dp));

        int ans = DFS(nums, i, j);

        for (auto row : tuples)
        {
            for (int i : row)
            {
                cout << i << " ";
            }
            cout << endl;
        }

        return ans;
    }
};