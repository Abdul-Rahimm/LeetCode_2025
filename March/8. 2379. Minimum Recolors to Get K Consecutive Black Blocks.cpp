class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {

        int n = blocks.size();

        int w = 0;
        int ans = INT_MAX;

        for (int i = 0; i < k; i++)
            if (blocks[i] == 'W')
                w++;

        ans = min(ans, w);

        int i = k;

        while (i < n)
        {
            if (blocks[i - k] == 'W')
                w--;
            if (blocks[i] == 'W')
                w++;

            ans = min(ans, w);
            if (w == 0)
                return 0;

            i++;
        }

        return ans;
    }
};