#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, const vector<vector<int>> &graph, vector<int> &color, int c)
{
    for (int i = 0; i < graph.size(); i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(const vector<vector<int>> &graph, int m, vector<int> &color, int v)
{
    // base case: If all vertices are assigned a color then return true
    if (v == graph.size())
        return true;

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++)
    {
        // Check if assignment of color c to v is fine
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            // If assigning color c doesn't lead to a solution then remove it
            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(const vector<vector<int>> &graph, int m)
{
    vector<int> color(graph.size(), 0);
    if (!graphColoringUtil(graph, m, color, 0))
    {
        cout << "No solution exists" << endl;
        return false;
    }

    cout << "Solution exists: Following are the assigned colors:" << endl;
    for (int i = 0; i < graph.size(); i++)
        cout << "Vertex " << i << " --->  Color " << color[i] << endl;
    return true;
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 1, 1},
                                 {1, 0, 1, 0},
                                 {1, 1, 0, 1},
                                 {1, 0, 1, 0}};
    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}
