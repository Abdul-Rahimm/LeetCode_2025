class Solution
{
public:
    vector<int> getLongestSubsequence(int i, vector<int> &groups)
    {
        int n = groups.size();
        vector<int> zero, one;

        // either start from 0
        int toggle = 0;
        for (int i = 0; i < n; i++)
        {
            if (groups[i] == toggle)
            {
                zero.push_back(i);
                toggle = toggle == 0 ? 1 : 0;
            }
        }

        toggle = 1;
        // or start from 1
        for (int i = 0; i < n; i++)
        {
            if (groups[i] == toggle)
            {
                one.push_back(i);
                toggle = toggle == 0 ? 1 : 0;
            }
        }

        return one.size() >= zero.size() ? one : zero;
    }

    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {

        vector<int> longestSubsequence = getLongestSubsequence(0, groups);
        vector<string> ans;

        for (int i : longestSubsequence)
        {
            ans.push_back(words[i]);
        }

        return ans;
    }
};