class Solution
{
public:
    vector<int> BobPath;

    bool findBobPath(int i, int target, unordered_map<int, vector<int>> &mp, vector<int> &BobPath)
    {

        BobPath.push_back(i);

        if (i == target)
            return true;

        for (int ngbr : mp[i])
        {
            if (findBobPath(ngbr, target, mp, BobPath))
                return true;
        }

        BobPath.pop_back();
        return false;
    }

    int DFS(int i, int time, unordered_map<int, set<int>> bobVisitTime, unordered_map<int, vector<int>> mp, vector<int> &amount)
    {

        int score = amount[i];
        if (bobVisitTime[time].find(i) != bobVisitTime[time].end())
        {
            // bob ne yeh node visit kia hua
            if (BobPath[time] == i)
            {
                score = amount[i] / 2;
            }
            else
            {
                score = 0;
            }
        }

        if (mp.find(i) == mp.end())
            return score;
        int curr = -1;

        for (auto ngbr : mp[i])
        {
            curr = max(curr, DFS(ngbr, time + 1, bobVisitTime, mp, amount));
        }

        return score + curr;
    }

    int mostProfitablePath(vector<vector<int>> &edges, int bobStart, vector<int> &amount)
    {

        unordered_map<int, vector<int>> mp;
        int ans = 0;

        for (auto row : edges)
        {
            int u = row[0];
            int v = row[1];

            mp[u].push_back(v);
        }

        findBobPath(0, bobStart, mp, BobPath);
        reverse(BobPath.begin(), BobPath.end());

        // at each second how many nodes has bob visited. this is for efficiency.
        unordered_map<int, set<int>> bobVisitTime;
        set<int> curr;

        for (int i = 0; i < BobPath.size(); i++)
        {
            curr.insert(BobPath[i]);
            bobVisitTime[i] = curr;
        }

        for (auto row : bobVisitTime)
        {
            cout << row.first << " : ";
            for (int i : row.second)
                cout << i << " ";
            cout << endl;
        }

        // calculate the most value time for Alice
        return DFS(0, 0, bobVisitTime, mp, amount);

        // queue<int> alice, bob;

        // alice.push(0);
        // bob.push(bobStart);     BobPath.pop_back(); // since his current pos is already in quque

        // while(!alice.empty() or !bob.empty()){

        //     int bobCurrent   = bob.front();     bob.pop();
        //     if(BobPath.size() > 0){
        //         bob.push(BobPath[Bobpath.size()-1]);
        //         BobPath.pop_back();
        //     }

        //     int aliceCurrent = alice.front();   alice.pop();

        //     if(bobCurrent == aliceCurrent){
        //         ans += amount[bobCurrent]/2;
        //     }
        //     else{
        //         ans += amount[aliceCurrent];
        //     }

        //     amount[bobCurrent] = 0;
        // }

        return 0;
    }
};