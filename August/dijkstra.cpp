#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

struct Edge
{
    int destination;
    int weight;
};

class Graph
{
private:
    int V;
    vector<vector<Edge>> adjacencyList;

public:
    Graph(int vertices) : V(vertices)
    {
        adjacencyList.resize(vertices);
    }

    void addEdge(int source, int destination, int weight)
    {
        Edge edge = {destination, weight};
        adjacencyList[source].push_back(edge);
    }

    vector<int> dijkstra(int startVertex)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> distance(V, numeric_limits<int>::max());

        pq.push(make_pair(0, startVertex));
        distance[startVertex] = 0;

        vector<bool> processed(V, false);

        vector<int> predecessor(V, -1);

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (processed[u])
            {
                continue;
            }

            processed[u] = true;

            for (const Edge &edge : adjacencyList[u])
            {
                int v = edge.destination;
                int weight = edge.weight;

                if (!processed[v] && distance[u] != numeric_limits<int>::max() &&
                    distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    predecessor[v] = u;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }

        cout << "Vertex\tDistance\tPath" << endl;
        for (int i = 0; i < V; i++)
        {
            cout << startVertex << " -> " << i << "\t" << distance[i] << "\t\t";
            printPath(startVertex, i, predecessor);
            cout << endl;
        }

        return distance;
    }

    void printPath(int source, int destination, const vector<int> &predecessor)
    {
        if (destination == source)
        {
            cout << source;
            return;
        }

        if (predecessor[destination] == -1)
        {
            cout << "No path";
            return;
        }

        printPath(source, predecessor[destination], predecessor);
        cout << " -> " << destination;
    }
};

int main()
{
    Graph graph(6);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 3, 4);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 1);
    graph.addEdge(4, 5, 5);

    // Find shortest paths from vertex 0
    cout << "Shortest paths from vertex 0:" << endl;
    vector<int> distances = graph.dijkstra(0);

    return 0;
}
