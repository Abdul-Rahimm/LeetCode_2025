class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        map<int, int> mp;

        for (int i : nums)
            mp[i]++;

        for (auto row : mp)
            if (row.second % 2 != 0)
                return false;

        return true;
    }
};