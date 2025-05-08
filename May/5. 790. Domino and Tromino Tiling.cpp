class Solution
{
public:
    int mod = 1e9 + 7;
    int numTilings(int n)
    {
        vector<int> ans(n + 10);
        ans[1] = 1;
        ans[2] = 2;
        ans[3] = 5;

        for (int i = 4; i <= n; i++)
            ans[i] = ((2 * ans[i - 1] % mod) + (ans[i - 3] % mod)) % mod;

        return ans[n];
    }
};