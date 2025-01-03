// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();

        vector<long long> right(n + 1, 0), left(n + 1, 0);

        long long rightSum = 0, leftSum = 0;
        for (int i = 0, j = n; i < n; i++, j--)
        {
            rightSum += nums[i];
            leftSum += nums[n - 1 - i];

            left[n - 1 - i] = leftSum;
            right[i + 1] = rightSum;
        }

        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (right[i] >= left[i])
                ans++;
        }

        return ans;
    }
};
