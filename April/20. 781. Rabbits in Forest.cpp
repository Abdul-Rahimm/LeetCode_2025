class Solution
{
public:
    int numRabbits(vector<int> &nums)
    {
        int ans = 0;

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {

            if (mp.find(nums[i]) == mp.end())
            {
                ans += nums[i] + 1;
            }

            mp[nums[i]]++;

            if (mp[nums[i]] == nums[i] + 1)
                mp.erase(nums[i]);
        }

        return ans;
    }
};