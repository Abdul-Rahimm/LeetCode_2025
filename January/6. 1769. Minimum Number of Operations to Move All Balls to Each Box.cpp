// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    vector<int> minOperations(string nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        unordered_set<int> st;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == '1')
                st.insert(i);
        }

        for (int i = 0; i < n; i++)
        {
            int curr = i;

            for (int pos : st)
            {
                if (pos == curr)
                    continue;

                ans[curr] += abs(curr - pos);
            }
        }

        return ans;
    }
};
