class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        set<pair<int, int>> st;
        set<int> ans;

        int index = 0;
        for (int i : digits)
        {
            if (i % 2 == 0)
                st.insert({i, index});

            index++;
        }

        for (auto &[end, index] : st)
        {
            for (int i = 0; i < digits.size() - 1; i++)
            {
                for (int j = i + 1; j < digits.size(); j++)
                {
                    if (i == index or j == index)
                        continue;

                    if (digits[i] > 0)
                    {
                        int number = end + digits[i] * 100 + digits[j] * 10;
                        ans.insert(number);
                    }
                    if (digits[j] > 0)
                    {
                        int alternative =
                            end + digits[j] * 100 + digits[i] * 10;
                        ans.insert(alternative);
                    }
                }
            }
        }

        vector<int> ret(ans.begin(), ans.end());

        return ret;
    }
};