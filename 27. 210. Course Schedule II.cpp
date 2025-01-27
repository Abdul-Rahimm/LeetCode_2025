class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &prereq)
    {

        unordered_map<int, vector<int>> adj;
        vector<int> order;
        vector<int> indegree(n, 0);

        for (auto row : prereq)
        {
            int u = row[1];
            int v = row[0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            order.push_back(node);

            // see where u can go from node
            // decrease their in order

            for (int ngbr : adj[node])
            {
                indegree[ngbr]--;

                if (indegree[ngbr] == 0)
                    q.push(ngbr);
            }
        }

        if (order.size() != n)
            return {};

        return order;
    }
};