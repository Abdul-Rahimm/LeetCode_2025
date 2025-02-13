class Solution
{
public:
    void print(priority_queue<int, vector<int>, greater<int>> pq)
    {
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
    }
    int minOperations(vector<int> &nums, int k)
    {
        // min heap
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }

        int count = 0;
        while (pq.top() < k)
        {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();

            pq.push(min(x, y) * 2 + max(x, y));
            count++;
        }

        return count;
    }
};