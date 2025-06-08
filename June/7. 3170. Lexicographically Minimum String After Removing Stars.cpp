class Solution
{
public:
    string clearStars(string s)
    {

        int n = s.size();
        string ans(n, ' ');

        priority_queue<pair<char, int>, vector<pair<char, int>>,
                       decltype([](const pair<char, int> &a, const pair<char, int> &b)
                                {
                               if (a.first != b.first)
                                   return a.first > b.first;
    
                               return a.second < b.second; })>
            pq;

        for (int i = 0; i < n; i++)
        {
            if (s[i] != '*')
            {
                pq.push({s[i], i});
            }
            else
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            char curr = pq.top().first;
            int index = pq.top().second;
            pq.pop();

            ans[index] = curr;
        }

        string ret;
        for (char i : ans)
        {
            if (i != ' ')
                ret.push_back(i);
        }

        return ret;
    }
};