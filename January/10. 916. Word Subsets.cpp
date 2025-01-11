// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        map<char, int> mpTwo;
        vector<string> ans;

        for (string i : words2)
        {
            map<char, int> tempTwo;

            for (char ch : i)
            {
                tempTwo[ch]++;
            }

            for (auto row : tempTwo)
            {
                char val = row.first;
                int freq = row.second;

                mpTwo[val] = max(mpTwo[val], freq);
            }
        }

        for (string i : words1)
        {
            map<char, int> mpOne;
            bool status = true; // assuming we will add the word

            for (char ch : i)
            {
                mpOne[ch]++;
            }

            for (auto row : mpTwo)
            {
                char val = row.first;
                int freq = row.second;

                if (freq > mpOne[val])
                {
                    status = false; // we wont add the word
                    break;
                }
            }

            if (status)
                ans.push_back(i);
        }

        return ans;
    }
};