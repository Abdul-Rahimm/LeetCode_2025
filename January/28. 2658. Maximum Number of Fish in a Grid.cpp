class Solution
{
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int DFS(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] <= 0)
        {
            return 0;
        }

        int score = grid[i][j];
        grid[i][j] = -1;

        for (auto dir : directions)
        {
            int newi = i + dir[0];
            int newj = j + dir[1];

            score += DFS(newi, newj, grid);
        }

        return score;
    }

    int findMaxFish(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] > 0)
                {
                    ans = max(ans, DFS(i, j, grid));
                }
            }
        }

        return ans;
    }
};