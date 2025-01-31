class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dp[501][501];
    int DFS(int i, int j, vector<vector<int>>& grid) {

        if(dp[i][j] != -1)
            return dp[i][j];

        int score = 1;
        grid[i][j] = 0; // mark it visited

        for (auto dir : directions) {
            int newi = i + dir[0];
            int newj = j + dir[1];

            if (newi < 0 or newi >= grid.size() or newj < 0 or
                newj >= grid[0].size() or grid[newi][newj] == 0)
                continue;

            score += DFS(newi, newj, grid);
        }

        return dp[i][j] = score;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int mx = 0;
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {
                    vector<vector<int>> copy = grid;

                    mx = max(mx, DFS(i, j, copy));
                }
            }
        }

        return mx == 0 ? n * n : mx;
    }
};