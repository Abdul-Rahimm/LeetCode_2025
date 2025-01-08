// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int countPrefixSuffixPairs(vector<string> &words)
{
    int n = words.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        string current = words[i];
        for (int j = i + 1; j < n; j++)
        {

            string temp = words[j];

            if (current.size() > temp.size())
                continue;

            int x = 0; // for smaller
            int y = 0, z = temp.size() - current.size();

            while (x < current.size() and current[x] == temp[y] and current[x] == temp[z])
            {
                x++;
                y++;
                z++;
            }

            if (x == current.size())
                ans++;
        }
    }

    return ans;
}