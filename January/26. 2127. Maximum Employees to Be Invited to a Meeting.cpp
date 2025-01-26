class Solution
{
public:
    void DFS(int i, map<int, vector<int>> mp, vector<int> &ngbr,
             vector<int> &fav)
    {
        if (ngbr[i] == 2 || ngbr[fav[i]] == 2)
            return;

        for (int x : mp[i])
            if (x == fav[i])
                return;

        ngbr[i]++;
        ngbr[fav[i]]++;

        mp[i].push_back(fav[i]);
        mp[fav[i]].push_back(i);

        DFS(fav[i], mp, ngbr, fav);
    }

    int maximumInvitations(vector<int> &fav)
    {
        map<int, vector<int>> mp;

        int n = fav.size();
        int mostFav = 0;
        for (int i = 0; i < n; i++)
        {
            int favorite = fav[i];

            mp[favorite].push_back(i);

            if (mp[favorite].size() > mostFav)
            {
                mostFav = mp[favorite].size();
                mostFav = favorite; // this has the most number of peple wanting
                                    // to sit with him
            }
        }

        vector<int> ngbr(n, 0); // no people sitting right now

        mp.clear();
        DFS(mostFav, mp, ngbr, fav);

        for (int i = 0; i < n; i++)
        {
            if (ngbr[i] < 2)
            {
                DFS(i, mp, ngbr, fav);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (ngbr[i] >= 1)
            {
                ans++;
            }
        }

        return ans;
    }
};