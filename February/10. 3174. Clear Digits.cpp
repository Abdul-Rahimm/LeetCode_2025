class Solution
{
public:
    string clearDigits(string s)
    {
        int n = s.size();

        vector<bool> status(n, false);
        set<int> st; // to store the indexes which i do not need

        for (int i = 0; i < n; i++)
        {
            if (s[i] >= '0' and s[i] <= '9')
            {
                // see the closest character to its left

                for (int j = i - 1; j >= 0; j--)
                {
                    if (isalpha(s[j]) and status[j] == false)
                    {
                        status[j] = true;
                        st.insert(i); // store the indexes of chars which needa be removed
                        st.insert(j);
                        break;
                    }
                }
            }
        }

        string ans = "";

        for (int i = 0; i < n; i++)
        {
            if (st.find(i) == st.end())
            {
                ans += s[i];
            }
        }

        return ans;
    }
};