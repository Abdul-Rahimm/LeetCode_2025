// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        int n = s.size();
        unordered_map<char, int> mp;

        if (k == n)
            return true;
        if (k > n)
            return false;

        for (char i : s)
            mp[i]++;

        int even = 0;
        int odd = 0;

        for (auto &[ch, freq] : mp)
            if (freq % 2)
                odd++;
            else
                even++;

        if (odd <= k)
            return true;

        return false;
    }
};