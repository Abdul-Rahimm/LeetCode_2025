class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++)
        {
            int mainColor = colors[i];

            if (mainColor == -1)
            {
                // traverse the adjacency list and assign it opp color to the ngbr
                vector<int> ngbrs = graph[i];

                for (int j = 0; j < ngbrs.size(); j++)
                {
                    int color = colors[ngbrs[j]];
                    if (color == 1)
                    {
                        mainColor = 2;
                        colors[j] = 2;
                        break;
                    }
                    if (color == 2)
                    {
                        mainColor = 1;
                        colors[j] = 1;
                        break;
                    }
                }
            }

            if (mainColor == -1)
            {
                mainColor = 1;
                colors[i] = 1;
            }

            cout << "at index " << i << " main color is " << mainColor << endl;

            // main color can be either 1 or 2
            // nodes ka color will be opposite of either 1 or 2

            vector<int> ngbrs = graph[i];

            for (int j = 0; j < ngbrs.size(); j++)
            {
                if (mainColor == colors[ngbrs[j]] and colors[ngbrs[j]] != -1)
                    return false;

                if (mainColor == 1)
                {
                    colors[ngbrs[j]] = 2;
                }
                else if (mainColor == 2)
                {
                    colors[ngbrs[j]] = 1;
                }

                cout << "at index " << i << " color of ngbr " << ngbrs[j] << " is " << colors[ngbrs[j]] << endl;
            }
        }

        return true;
    }
};