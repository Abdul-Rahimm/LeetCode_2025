// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void print(vector<vector<int>> &grid)
{
    for (auto row : grid)
    {
        for (int i : row)
        {
            cout << " "[i < 0] << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}
vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();

    if (n == 1)
        return grid;

    int horizontalIterations = n - 2;
    int verticalIterations = n - 1;

    for (int count = 0; count <= horizontalIterations; count++)
    {
        int i = 0;
        int j = n - horizontalIterations - count;

        multiset<int> st;

        while (j < n and i < n and i > 0 and j > 0)
        {
            st.insert(grid[i][j]);
            // cout << grid[i][j] << " ";
            i++;
            j++;
        }
        // cout << endl;
        i = 0;
        j = n - horizontalIterations - count;

        for (int number : st)
        {
            grid[i][j] = number;
            i++;
            j++;
        }

        print(grid);
    }

    for (int count = 0; count < verticalIterations; count++)
    {
        int i = 0 + count;
        int j = 0;

        multiset<int, greater<int>> st;

        while (j < n and i < n and i > 0 and j > 0)

        {
            st.insert(grid[i][j]);
            i++;
            j++;
        }

        i = 0 + count;
        j = 0;

        for (int number : st)
        {
            grid[i][j] = number;
            i++;
            j++;
        }
        print(grid);
    }

    return grid;
}

int main()
{
    vii grid{{2, -1, -1, 2, -4}, {-3, 5, -2, -4, -4}, {2, -5, 2, 4, 2}, {-5, 2, 3, 3, 1}, {-5, -2, 2, -2, 2}};
    vii ans = sortMatrix(grid);
}