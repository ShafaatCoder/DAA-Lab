#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, const vector<vector<int>> &graph, vector<int> &path, int pos)
{
    // Check if this vertex is an adjacent vertex of the previously added vertex.
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included.
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCycleUtil(const vector<vector<int>> &graph, vector<int> &path, int pos)
{
    // base case: If all vertices are included in the cycle
    if (pos == graph.size())
    {
        // And if there is an edge from the last included vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as a next candidate in Hamiltonian Cycle.
    for (int v = 1; v < graph.size(); v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            if (hamiltonianCycleUtil(graph, path, pos + 1))
                return true;

            // If adding vertex v doesn't lead to a solution, remove it
            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCycle(const vector<vector<int>> &graph)
{
    vector<int> path(graph.size(), -1);
    path[0] = 0; // Start at vertex 0

    if (!hamiltonianCycleUtil(graph, path, 1))
    {
        cout << "No Hamiltonian Cycle found" << endl;
        return false;
    }
    else
    {
        cout << "Hamiltonian Cycle exists: ";
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
        cout << path[0] << endl; // To show the cycle, print the start vertex at the end
        return true;
    }
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 0, 1, 0},
                                 {1, 0, 1, 1, 1},
                                 {0, 1, 0, 0, 1},
                                 {1, 1, 0, 0, 1},
                                 {0, 1, 1, 1, 0}};

    hamiltonianCycle(graph);
    return 0;
}
