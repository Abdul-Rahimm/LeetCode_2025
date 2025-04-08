class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> pehle(n), baad(n);

        long long ans = 0;

        pehle[0] = nums[0];
        baad[n - 1] = nums[n - 1];

        for (int i = 1, j = n - 2; i < n; i++, j--)
        {
            if (nums[i] > pehle[i - 1])
            {
                pehle[i] = nums[i];
            }
            else
            {
                pehle[i] = pehle[i - 1];
            }

            if (nums[j] > baad[j + 1])
            {
                baad[j] = nums[j];
            }
            else
            {
                baad[j] = baad[j + 1];
            }
        }

        for (int i = 1; i < n - 1; i++)
        {
            ans = max(ans, (long long)(pehle[i - 1] - nums[i]) * baad[i + 1]);
        }

        return ans;
    }
};