class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {

        // vector<int> ballsColor(limit+1, -1);    //mapping of balls and color
        vector<int> ans;
        unordered_map<int, set<int>> mp; // mapping of color vs balls
        // unordered_map<int, int> ballsColor;     //mapping of ball and its color

        for (auto row : queries)
        {
            int ball = row[0];
            int newColor = row[1];

            int currentColor = ballsColor.find(ball) == ballsColor.end() ? -1 : ballsColor[ball]; // what is the current color of the ball

            if (currentColor != -1)
            {
                mp[currentColor].erase(ball);

                if (mp[currentColor].size() == 0)
                    mp.erase(currentColor);
            }

            ballsColor[ball] = newColor;
            mp[newColor].insert(ball);

            ans.push_back(mp.size());
        }

        return ans;
    }
};