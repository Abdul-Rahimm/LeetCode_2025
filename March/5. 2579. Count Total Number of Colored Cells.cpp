class Solution
{
public:
    long long coloredCells(int n)
    {
        long long ans = 0;
        n--;

        ans += 2 * n + 1;

        for (int i = 0; i < n; i++)
        {
            long long x = 2 * i + 1;
            ans += 2 * x;
        }

        return ans;
    }
};