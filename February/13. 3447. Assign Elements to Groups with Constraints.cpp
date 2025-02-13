class Solution
{
public:
    vector<int> assignElements(vector<int> &groups, vector<int> &elements)
    {

        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < elements.size(); i++)
        {
            if (mp.find(elements[i]) == mp.end())
            {
                mp[elements[i]] = i;
            }
        }
        // 4 0
        // 2 1
        for (int num : groups)
        {
            int position = INT_MAX; // initally

            // find out the divisors
            for (int i = 1; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    // two divisors
                    //  i and num/i
                    if (mp.find(i) != mp.end())
                    {
                        position = min(position, mp[i]);
                    }
                    if (mp.find(num / i) != mp.end())
                    {
                        position = min(position, mp[num / i]);
                    }
                }
            }

            if (position == INT_MAX)
                position = -1;

            ans.push_back(position);
        }

        return ans;
    }
};