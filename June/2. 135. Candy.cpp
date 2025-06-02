class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int ans = 0;
        int n = ratings.size();

        for (int i = 0; i < ratings.size(); i++)
            pq.push({ratings[i], i});

        vector<int> scores(n, 1); // all unassigned

        while (!pq.empty())
        {
            int rating = pq.top().first;
            int index = pq.top().second;
            cout << rating << " " << index << " --> ";
            pq.pop();

            // assign the score to current index now based on comparison
            int score = 1;
            if (index - 1 >= 0 and ratings[index - 1] < ratings[index])
            {
                score = max(score, scores[index - 1] + 1);
                scores[index] = score;
            }

            if (index + 1 < n and ratings[index + 1] < ratings[index])
            {
                score = max(score, scores[index + 1] + 1);
                scores[index] = score;
            }

            ans += score;
        }

        return ans;
    }
};