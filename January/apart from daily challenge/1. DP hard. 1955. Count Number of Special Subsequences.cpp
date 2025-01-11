// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    int dp[100001][4];
    int mod = 1e9 + 7;

    int solve(vector<int> &nums, int i, int last)
    {

        if (i >= nums.size())
            return last == 2;
        if (dp[i][last + 1] != -1)
            return dp[i][last + 1];

        int take = last + 1 == nums[i] ? ((solve(nums, i + 1, last + 1)) % mod + (solve(nums, i + 1, last)) % mod) % mod : 0;

        int nottake = solve(nums, i + 1, last) % mod;

        return dp[i][last + 1] = (take + nottake) % mod;
    }

    int countSpecialSubsequences(vector<int> &nums)
    {

        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};