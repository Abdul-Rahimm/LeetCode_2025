class Solution
{
public:
    long long dp[100001];
    long long solve(int i, vector<vector<int>> &questions)
    {
        if (i >= questions.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        long long skip = questions[i][1];

        long long take = questions[i][0] + solve(i + skip + 1, questions);
        long long nott = solve(i + 1, questions);

        return dp[i] = max(take, nott);
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, questions);
    }
};