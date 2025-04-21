class Solution
{
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void solve(int start, int k, int n, vector<int> &temp)
    {

        if (k == 0)
        {
            if (n == 0)
            {
                if (st.find(temp) == st.end())
                    ans.push_back(temp);
                st.insert(temp);
            }

            return;
        }

        for (int i = start; i <= 9; i++)
        {
            temp.push_back(i);
            // if (i < 9)
            solve(i + 1, k - 1, n - i, temp);
            temp.pop_back();
            // solve(i+1, k, n, temp);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {

        for (int i = 1; i < 10; i++)
        {
            vector<int> temp;
            solve(i, k, n, temp);
        }

        return ans;
    }
};