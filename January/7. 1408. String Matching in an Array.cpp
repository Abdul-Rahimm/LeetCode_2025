class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> ans;
        int n = words.size();

        unordered_set<string> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // see which is the larger word
                // smaller might be the substring
                string larger, smaller;

                if (words[i].size() > words[j].size())
                {
                    larger = words[i];
                    smaller = words[j];
                }
                else
                {
                    smaller = words[i];
                    larger = words[j];
                }

                // compare using two ptrs
                int l = 0; // for larger
                int s = 0; // for smaller
                int count = -1;
                int save = -1;

                while (l < larger.size() and s < smaller.size())
                {
                    if (larger[l] != smaller[s])
                    {
                        if (count == 0)
                        {
                            l++;
                            count = -1;
                        }
                        else
                            count = 0;

                        if (save != -1)
                            l = save + 1;

                        save = -1;
                        s = 0;
                    }
                    else
                    {
                        if (save == -1)
                            save = l;

                        l++;
                        s++;
                    }
                }

                if (s >= smaller.size())
                {
                    st.insert(smaller);
                }
            }
        }

        for (string word : st)
            ans.push_back(word);

        return ans;
    }
};