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
        int commonPart = 0;

        while (j < n)
        {

            sum += nums[j];
            int windowLen = j - i + 1;

            if (sum * windowLen < k)
            {
                j++;
                continue;
            }

            int subArraySize = j - i;
            int toAdd = (subArraySize * (subArraySize + 1)) / 2;

            cout << "Added " << toAdd << endl;
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
            commonPart = (diff * (diff + 1)) / 2;

            j++;

            if (j >= n)
            {
                int subArraySize = j - i;
                int toAdd = (subArraySize * (subArraySize + 1)) / 2;

                ans += toAdd - commonPart;
                commonPart = 0;
                cout << "Added " << toAdd << endl;
            }
        }

        return ans;
    }
};