#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minDistance(const vector<int> &dist, const vector<bool> &sptSet, int V)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(const vector<int> &dist, int V)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

void dijkstra(const vector<vector<int>> &graph, int src)
{
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V);
}

int main()
{
    vector<vector<int>> graph = {{0, 10, 20, 0, 0, 0},
                                 {10, 0, 0, 50, 10, 0},
                                 {20, 0, 0, 20, 33, 0},
                                 {0, 50, 20, 0, 20, 2},
                                 {0, 10, 33, 20, 0, 1},
                                 {0, 0, 0, 2, 1, 0}};

    dijkstra(graph, 0);

    return 0;
}
