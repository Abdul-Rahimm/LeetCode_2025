// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    int n, m;
    int dp[501][501][3];
    int solve(int i, int j, int rem, vector<vector<int>> &coins)
    {

        if (i == n - 1 && j == m - 1)
        {
            if (rem > 0 && coins[i][j] < 0)
            {
                return 0;
            }
            else
            {
                return coins[i][j];
            }
        }

        if (i >= n or j >= m)
            return INT_MIN;
        if (dp[i][j][rem] != INT_MIN)
            return dp[i][j][rem];

        int take = coins[i][j] + max(solve(i + 1, j, rem, coins),
                                     solve(i, j + 1, rem, coins));
        int nottake = INT_MIN;

        if (coins[i][j] < 0 and rem > 0)
        {
            nottake = max(solve(i + 1, j, rem - 1, coins),
                          solve(i, j + 1, rem - 1, coins));
        }

        return dp[i][j][rem] = max(take, nottake);
    }

    int maximumAmount(vector<vector<int>> &coins)
    {
        n = coins.size();
        m = coins[0].size();

        for (int i = 0; i < 501; i++)
        {
            for (int j = 0; j < 501; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(0, 0, 2, coins);
    }
};