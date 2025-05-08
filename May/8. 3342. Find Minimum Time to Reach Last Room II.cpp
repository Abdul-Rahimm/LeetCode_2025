class Solution
{
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size();
        int m = moveTime[0].size();
        int ans = 0;

        vector<vector<int>> costToVisit(n, vector<int>(m, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        costToVisit[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0, 0}); // cost, i, j, turn

        // if turn even --> add 1
        // else add 2

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int cost = top[0];
            int i = top[1];
            int j = top[2];
            int turn = top[3];

            if (i == n - 1 and j == m - 1)
                return cost;

            vis[i][j] = -1;

            for (vector<int> dir : directions)
            {
                int newi = i + dir[0];
                int newj = j + dir[1];

                if (newi >= 0 and newj >= 0 and newi < n and newj < m and vis[newi][newj] != -1)
                {
                    int waitTime = max(moveTime[newi][newj] - cost, 0);

                    if (cost + waitTime + 1 < costToVisit[newi][newj])
                    {
                        int extraTime = turn % 2 == 0 ? 1 : 2;

                        costToVisit[newi][newj] = cost + waitTime + extraTime;
                        pq.push({costToVisit[newi][newj], newi, newj, turn + 1});
                    }
                }
            }
        }

        return -1;
    }
};