#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INFINITY 9999
#define MAX 20

int G[MAX][MAX], spanning[MAX][MAX], n;

int prims();

int main()
{
    int i, j, total_cost;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "\nEnter the adjacency matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> G[i][j];
        }
    }

    total_cost = prims();
    cout << "\nSpanning tree matrix:\n";

    for (i = 0; i < n; i++)
    {
        cout << "\n";
        for (j = 0; j < n; j++)
        {
            cout << spanning[i][j] << "\t";
        }
    }

    cout << "\n\nTotal cost of spanning tree = " << total_cost;
    cout << "\n\n Name: Shovit Regmi\nRoll No.: 32\n";
    return 0;

}

int prims()
{
    int cost[MAX][MAX];
    int u, v, min_distance, distance[MAX], from[MAX];
    int visited[MAX], no_of_edges, min_cost, i, j;

    // Create cost[][] matrix and spanning[][] matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = G[i][j];
            }
            spanning[i][j] = 0;
        }
    }

    // Initialize visited[], distance[], and from[]
    distance[0] = 0;
    visited[0] = 1;
    for (i = 1; i < n; i++)
    {
        distance[i] = cost[0][i];
        from[i] = 0;
        visited[i] = 0;
    }

    min_cost = 0;        // Cost of the spanning tree
    no_of_edges = n - 1; // Number of edges to be added

    while (no_of_edges > 0)
    {
        // Find the vertex at minimum distance from the tree
        min_distance = INFINITY;
        for (i = 1; i < n; i++)
        {
            if (visited[i] == 0 && distance[i] < min_distance)
            {
                v = i;
                min_distance = distance[i];
            }
        }

        u = from[v];

        // Insert the edge into the spanning tree
        spanning[u][v] = distance[v];
        spanning[v][u] = distance[v];
        no_of_edges--;
        visited[v] = 1;

        // Update the distance[] array
        for (i = 1; i < n; i++)
        {
            if (visited[i] == 0 && cost[i][v] < distance[i])
            {
                distance[i] = cost[i][v];
                from[i] = v;
            }
        }

        min_cost = min_cost + cost[u][v];
    }

    return min_cost;
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";
}
