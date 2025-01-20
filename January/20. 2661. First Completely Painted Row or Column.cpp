class Solution
{
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void print(vector<vector<pair<int, int>>> position)
    {
        int n = position.size();
        int m = position[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << position[i][j].first << "," << position[i][j].second << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<int, int>>> position(n, vector<pair<int, int>>(m, {0, 0}));
        map<int, pair<int, int>> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int value = grid[i][j];

                mp[value] = {i, j};
            }
        }

        for (int j = 0; j < arr.size(); j++)
        {

            int i = arr[j];
            pair<int, int> pos = mp[i];
            int x = pos.first;
            int y = pos.second;

            position[x][y].first++;
            position[x][y].second++;

            for (int i = 0; i <= 1; i++)
            {
                vector<int> dir = directions[i];
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if (new_x < 0 or new_x >= n or new_y < 0 or new_y >= m)
                    continue;

                int value = grid[new_x][new_y];
                pair<int, int> ngbr = mp[value]; // these are the coordinates

                int one = position[ngbr.first][ngbr.second].first;
                int two = position[ngbr.first][ngbr.second].second;

                position[x][y].first += one;
                // position[x][y].second += two;
            }

            for (int i = 2; i <= 3; i++)
            {
                vector<int> dir = directions[i];
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if (new_x < 0 or new_x >= n or new_y < 0 or new_y >= m)
                    continue;

                int value = grid[new_x][new_y];
                pair<int, int> ngbr = mp[value]; // these are the coordinates

                int one = position[ngbr.first][ngbr.second].first;
                int two = position[ngbr.first][ngbr.second].second;

                // position[x][y].first += one;
                position[x][y].second += two;
            }

            print(position);

            if (position[x][y].first == m or position[x][y].second == n)
                return j;
        }

        return 0;
    }
};