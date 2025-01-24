class Solution
{
public:
    bool DFS(int i, vector<int> &vis, vector<vector<int>> &graph)
    {
        if (vis[i] == 1)
            return false;

        cout << "reached " << i << endl;
        vis[i] = 1;
        bool isSafe = true; // assuming safe node

        if (graph[i].size() == 0)
        {
            vis[i] = 2;  // safe node
            return true; // terminal node
        }

        for (int ngbr : graph[i])
        {

            cout << "checking " << i << "'s ngbr " << ngbr << endl;
            bool status = DFS(ngbr, vis, graph);

            cout << "ngbr " << ngbr << " returned " << status << endl;
            if (status)
            {
                vis[ngbr] = 2; // safe node
            }

            isSafe = isSafe && status;
        }

        if (isSafe)
            vis[i] = 2; // safe node

        return isSafe;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<int> visited(n, -1);

        for (int i = 0; i < n; i++)
            if (visited[i] == -1)
                DFS(i, visited, graph);

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 2)
                ans.push_back(i);
        }

        return ans;
    }
};