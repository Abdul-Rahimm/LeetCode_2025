class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        set<pair<int, int>> st;

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    count++;
            }

            if (count > 1)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        st.insert({i, j});
                    }
                }
            }
        }

        for (int j = 0; j < m; j++)
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (grid[i][j] == 1)
                    count++;
            }

            if (count > 1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (grid[i][j] == 1 and st.find({i, j}) == st.end())
                    {
                        st.insert({i, j});
                    }
                }
            }
        }

        return st.size();
    }
};