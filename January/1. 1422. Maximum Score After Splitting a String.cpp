// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.size();

        vector<int> zeros(n), ones(n);
        int countZero = 0, countOne = 0;

        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            if (s[i] == '0')
                countZero++;
            if (s[j] == '1')
                countOne++;

            zeros[i] = countZero;
            ones[j] = countOne;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, zeros[i] + ones[i + 1]);
        }

        return ans;
    }
};