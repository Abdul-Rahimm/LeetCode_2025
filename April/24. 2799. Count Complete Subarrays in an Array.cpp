class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        set<int> st(nums.begin(), nums.end());
        int count = st.size();

        int ans = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;

        map<int, int> mp;

        while (j < n)
        {
            int curr = nums[j];

            mp[curr]++;

            while (mp.size() == count)
            {
                ans += (n - j);

                mp[nums[i]]--;

                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);

                i++;
            }

            j++;
        }

        return ans;
    }
};