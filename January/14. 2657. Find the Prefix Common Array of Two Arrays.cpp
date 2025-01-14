// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {

        map<int, vector<char>> mp;
        int n = A.size();

        vector<int> ans(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++)
        {

            mp[A[i]].push_back('a');
            if (mp[A[i]].size() == 2)
            {
                count++;
            }

            mp[B[i]].push_back('b');
            if (mp[B[i]].size() == 2)
            {
                count++;
            }

            ans[i] = count;
        }

        return ans;
    }
};