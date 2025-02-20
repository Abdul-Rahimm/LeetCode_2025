class Solution
{
public:
    string ans;
    bool recur(string curr, int limit, unordered_set<string> &st)
    {
        if (limit == 0)
        {
            cout << curr << endl;
            if (st.find(curr) == st.end())
            {
                ans = curr;
                return true;
            }

            return false;
        }

        // left
        bool left = recur(curr + '0', limit - 1, st);

        if (left)
            return true;

        // right
        bool right = recur(curr + '1', limit - 1, st);
        if (right)
            return true;

        return false;
    }

    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums[0].size();
        unordered_set<string> st(nums.begin(), nums.end());

        recur("", n, st);

        return ans;
    }
};