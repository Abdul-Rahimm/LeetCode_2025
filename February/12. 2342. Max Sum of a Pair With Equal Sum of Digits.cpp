class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, multiset<int, greater<int>>> mp;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            int curr = nums[i];

            while (curr > 0)
            {
                int digit = curr % 10;
                curr /= 10;

                sum += digit;
            }

            mp[sum].insert(nums[i]);
        }

        int ans = -1;

        for (auto row : mp)
        {
            if (row.second.size() < 2)
                continue;

            // just check the first two entries
            int count = 0;
            int curr = 0;
            for (int i : row.second)
            {
                curr += i;
                count++;

                if (count == 2)
                    break;
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};