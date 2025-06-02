
class Solution
{
public:
    long long distributeCandies(int n, int limit)
    {
        long long ans = 0;

        // min candies for child1 = consider child2 and child3 as one child. at max they can have 2(limit) candies
        // therefore min candies for child1 are n - 2(limit)

        for (int i = max(0, n - (2 * limit)); i <= min(limit, n); i++)
        {

            // for child 2 and child 3
            long long remaining = n - i;

            long long minChild2 = max(0ll, remaining - limit);
            long long maxChild2 = min((long long)limit, remaining);

            // calculating the possibilities
            ans += maxChild2 - minChild2 + 1;
        }
        return ans;
    }
};