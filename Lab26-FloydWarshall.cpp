#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floydWarshall(vector<vector<int>> &graph, int n)
{
    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "\nShortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;

    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix (use a large value or INT_MAX for no path):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
            if (i != j && graph[i][j] == 0)
            {
                graph[i][j] = INT_MAX;
            }
        }
    }

    floydWarshall(graph, n);
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}
