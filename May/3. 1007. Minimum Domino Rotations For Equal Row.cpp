class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int a = tops[0];
        int b = bottoms[0];

        // its either a or b
        auto check = [&](int num) -> int
        {
            int top = 0, bottom = 0;
            int same = 0;

            for (int i = 0; i < tops.size(); i++)
            {
                if (tops[i] != num and bottoms[i] != num)
                    return INT_MAX;

                if (tops[i] == num)
                    top++;
                if (bottoms[i] == num)
                    bottom++;
                if (tops[i] == bottoms[i] and tops[i] == num)
                    same++;
            }

            int ans = min(top, bottom) - same;
            return ans;
        };

        return min(check(a), check(b)) == INT_MAX ? -1 : min(check(a), check(b));
    }
};