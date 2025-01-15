class Solution
{
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList)
    {
        int n = wordList.size();

        set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty())
        {
            int nodes = q.size();

            while (nodes--)
            {
                string current = q.front();
                q.pop();

                for (int i = 0; i < current.size(); i++)
                {
                    // try with each char seperately
                    char original = current[i];

                    for (int j = 0; j < 26; j++)
                    {
                        if ('a' + j == original)
                            continue;

                        current[i] = 'a' + j;

                        if (st.find(current) != st.end())
                        {
                            if (current == endWord)
                                return level + 1;

                            q.push(current);
                            st.erase(current);
                        }
                    }

                    current[i] = original;
                }
            }
            level++;
        }

        return 0;
    }
};