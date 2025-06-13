class Solution
{
public:
    int minimizeMax(vector<int> &nums, int p)
    {
        int n = nums.size();
        vector<bool> visit(n, false);
        int ans = 0;

        // 1 1 2 3 7 10
        sort(nums.begin(), nums.end());
        if (p * 2 == n)
        {
            for (int i = 0; i < n; i += 2)
            {
                int diff = abs(nums[i] - nums[i + 1]);
                ans = max(ans, diff);
            }

            return ans;
        }
        priority_queue<int, vector<int>, greater<int>> pq;

        // 1 2 2 2 5
        for (int i = 1; i < n - 1; i += 2)
        {
            // select which to make pair with
            int left = INT_MAX;
            int right = INT_MAX;
            visit[i] = true;

            if (visit[i - 1] == false)
            {
                left = abs(nums[i - 1] - nums[i]);
            }
            if (visit[i + 1] == false)
            {
                right = abs(nums[i + 1] - nums[i]);
            }

            if (left < right)
            {
                visit[i - 1] = true;
                pq.push(left);
            }
            else
            {
                visit[i + 1] = true;
                pq.push(right);
            }
        }

        while (!pq.empty() and p > 0)
        {
            ans = max(ans, pq.top());
            pq.pop();
            --p;
        }

        return ans;
    }
};