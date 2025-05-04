class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long long ans = 0;

        int i = 0;
        int j = 0;
        int n = nums.size();
        long long sum = 0;
        long long commonPart = 0;

        while (j <= n)
        {
            if (j == n)
            {
                int subArraySize = j - i;
                long long toAdd = ((long long)subArraySize * (subArraySize + 1)) / 2;

                ans += toAdd - commonPart;
                cout << "Added " << toAdd << " Minus " << commonPart << " i = " << i << " and j = " << j << endl;
                return ans;
            }

            sum += nums[j];
            int windowLen = j - i + 1;

            if (sum * windowLen < k)
            {
                j++;
                continue;
            }

            long long subArraySize = j - i;
            long long toAdd = ((long long)subArraySize * (subArraySize + 1)) / (long long)2;

            cout << "Added " << toAdd << " Minus " << commonPart << " i = " << i << " and j = " << j << endl;
            ans += toAdd - commonPart;
            commonPart = 0;

            while (sum * windowLen >= k)
            {
                sum -= nums[i];
                i++;

                windowLen--;
            }

            // Inclusion Exclusion Principle
            int diff = j - i;
            commonPart = ((long long)diff * (diff + 1)) / 2;

            j++;
        }

        return ans;
    }
};