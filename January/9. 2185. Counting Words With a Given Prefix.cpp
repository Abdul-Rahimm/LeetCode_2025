// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int prefixCount(vector<string> &words, string pref)
{
    int n = words.size();
    int sz = pref.size();
    int ans = 0;

    for (string word : words)
    {

        for (int i = 0; i < sz; i++)
        {
            if (word[i] != pref[i])
            {
                ans--;
                break;
            }
        }

        ans++;
    }

    return ans;
}