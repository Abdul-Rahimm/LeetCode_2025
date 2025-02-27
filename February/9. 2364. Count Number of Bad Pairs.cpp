class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long badPairs = 0;
        unordered_map<int, int> diffCount;

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = i - nums[i];

            // Count of previous positions with same difference
            int goodPairsCount = diffCount[diff];

            // Total possible pairs minus good pairs = bad pairs
            badPairs += pos - goodPairsCount;

            // Update count of positions with this difference
            diffCount[diff] = goodPairsCount + 1;
        }

        return badPairs;
    }
};