#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int find(int i, vector<int> &parent);
int uni(int i, int j, vector<int> &parent);

int main()
{
    int i, j, a, b, u, v, n, ne = 1;
    int min, mincost = 0;
    cout << "\nEnter the number of vertices: ";
    cin >> n;

    vector<vector<int>> cost(n + 1, vector<int>(n + 1));
    vector<int> parent(n + 1, 0);

    cout << "\nEnter the cost adjacency matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX; // Use INT_MAX to represent infinity
        }
    }

    cout << "The edges of Minimum Cost Spanning Tree are\n";
    while (ne < n)
    {
        for (i = 1, min = INT_MAX; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u, parent);
        v = find(v, parent);

        if (uni(u, v, parent))
        {
            cout << ne++ << " edge (" << a << "," << b << ") = " << min << endl;
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INT_MAX;
    }

    cout << "\n\tMinimum cost = " << mincost << endl;

    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}

int find(int i, vector<int> &parent)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j, vector<int> &parent)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
