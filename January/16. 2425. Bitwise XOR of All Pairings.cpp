class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() % 2 == 0 and nums2.size() % 2 == 0)
            return 0;

        int allXorNums2 = 0;
        int allXorNums1 = 0;

        for (int i : nums2)
        {
            allXorNums2 ^= i;
        }
        for (int i : nums1)
        {
            allXorNums1 ^= i;
        }

        if (nums1.size() % 2 == 0 and nums2.size() % 2 == 1)
            return allXorNums1;
        else if (nums1.size() % 2 == 1 and nums2.size() % 2 == 0)
        {
            return allXorNums2;
        }
        else
        {
            return allXorNums1 ^ allXorNums2;
        }
    }
};