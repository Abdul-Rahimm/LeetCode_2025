class Solution
{
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> answer(n, vector<int>(m, -1));
        queue<vector<int>> q; //{value, i, j}

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j] == 1)
                {
                    answer[i][j] = -2; // mark it visited, later mark it 0

                    // after marking water --> push it into queue
                    q.push({0, i, j});
                }
            }
        }

        while (!q.empty())
        {

            vector<int> curr = q.front();
            q.pop();
            int val = curr[0];
            int i = curr[1];
            int j = curr[2];

            answer[i][j] = val;

            // now explore all 4 neighbours
            for (auto dir : directions)
            {
                int newi = i + dir[0];
                int newj = j + dir[1];

                if (newi < 0 or newi >= n or newj < 0 or newj >= m or answer[newi][newj] != -1)
                {
                    continue;
                }

                answer[newi][newj] = -2;
                q.push({val + 1, newi, newj});
            }
        }

        return answer;
    }
};