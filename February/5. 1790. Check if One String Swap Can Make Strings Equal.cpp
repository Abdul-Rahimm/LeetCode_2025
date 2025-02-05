class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        map<char, int> mp1, mp2;
        int n = s1.size();

        for (char i : s1)
            mp1[i]++;

        for (char i : s2)
            mp2[i]++;

        int unmatched = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
                unmatched++;
        }

        return mp1 == mp2 and unmatched <= 2;
    }
};