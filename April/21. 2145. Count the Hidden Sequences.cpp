class Solution
{
public:
    int numberOfArrays(vector<int> &diff, int lower, int upper)
    {

        long long mini = INT_MAX;
        long long maxi = INT_MIN;
        long long curr = 0;

        for (int i : diff)
        {
            curr += i;

            mini = min(mini, curr);
            maxi = max(maxi, curr);
        }

        int ans = 0;
        for (int i = lower; i <= upper; i++)
        {

            if ((i + maxi) >= lower and (i + maxi) <= upper and
                (i + mini) >= lower and (i + mini) <= upper)
                ans++;
        }

        return ans;
    }
};