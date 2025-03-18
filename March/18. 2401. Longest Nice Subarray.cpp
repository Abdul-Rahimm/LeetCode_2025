class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int trackBits = 0; // currentBitSet
        int i = 0;         // window start
        int maxLen = 0;

        // j --> window end
        for (int j = 0; j < nums.size(); j++)
        {

            // shrink my window
            while ((trackBits & nums[j]) != 0)
            {
                trackBits ^= nums[i];
                i++;
            }

            // added nums[j] to my current window
            trackBits |= nums[j];

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};