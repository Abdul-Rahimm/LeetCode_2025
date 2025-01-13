// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    int minimumLength(string s)
    {
        map<char, int> mp;

        for (char i : s)
        {
            mp[i]++;
        }

        int ans = 0;

        for (auto row : mp)
        {
            if (row.second % 2 == 0)
                ans += 2;
            else
                ans++;
        }

        return ans;
    }
};