class Solution
{
public:
    int n, m;
    vector<vector<int>> directions{{0, 1}, {1, 0}};

    bool DFS(int i, int j, vector<vector<int>> &grid)
    {
        if (i == grid.size() - 1 and j == grid[0].size() - 1)
            return true;

        if (i >= n or j >= m or grid[i][j] == 0)
            return false;

        grid[i][j] = 0;

        return DFS(i, j + 1, grid) or DFS(i + 1, j, grid);
    }

    bool isPossibleToCutPath(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        int count = 0;

        count += DFS(0, 0, grid);
        grid[0][0] = 1;
        count += DFS(0, 0, grid);

        return count == 2 ? false : true;
    }
};