// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int countPalindromicSubsequence(string s)
{
    int n = s.size();

    unordered_set<char> letters;

    for (char i : s)
        letters.insert(i);

    int ans = 0;
    for (char letter : letters)
    {

        int left = -1;
        int right = -1;

        for (int i = 0; i < n; i++)
        {

            if (s[i] == letter)
            {
                if (left == -1)
                    left = i;

                right = i;
            }
        }

        unordered_set<char> uni;
        for (int middle = left + 1; middle < right; middle++)
        {
            uni.insert(s[middle]);
        }

        ans += uni.size();
    }

    return ans;
}