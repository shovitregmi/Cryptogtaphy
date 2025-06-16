#include <iostream>
#include <vector>

using namespace std;

void findVertexCover(int adjMatrix[][100], int totalVertices)
{
    vector<bool> visited(totalVertices, false);

    for (int i = 0; i < totalVertices; ++i)
    {
        if (!visited[i])
        {
            for (int j = 0; j < totalVertices; ++j)
            {
                if (adjMatrix[i][j] && !visited[j])
                {
                    visited[i] = true;
                    visited[j] = true;
                    break;
                }
            }
        }
    }

    cout << "The Vertex Cover is: ";
    for (int i = 0; i < totalVertices; ++i)
    {
        if (visited[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{

    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    int adjacencyMatrix[100][100];
    cout << "Enter the adjacency matrix:" << endl;
    for (int row = 0; row < numVertices; ++row)
    {
        for (int col = 0; col < numVertices; ++col)
        {
            cin >> adjacencyMatrix[row][col];
        }
    }

    findVertexCover(adjacencyMatrix, numVertices);
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}
