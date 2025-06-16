#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INFINITY 999

void dijkstra(int n, int v, vector<vector<int>>& cost, vector<int>& dist) {
    int i, u, count, w, min;
    vector<int> flag(n + 1, 0);

    for (i = 1; i <= n; i++) {
        flag[i] = 0;
        dist[i] = cost[v][i];
    }

    count = 2;
    while (count <= n) {
        min = INFINITY;
        for (w = 1; w <= n; w++) {
            if (dist[w] < min && !flag[w]) {
                min = dist[w];
                u = w;
            }
        }
        flag[u] = 1;
        count++;
        for (w = 1; w <= n; w++) {
            if ((dist[u] + cost[u][w] < dist[w]) && !flag[w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    int n, v, i, j;
    cout << "\nEnter the number of nodes: ";
    cin >> n;
    vector<vector<int>> cost(n + 1, vector<int>(n + 1));
    vector<int> dist(n + 1);

    cout << "\nEnter the cost matrix:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0) {
                cost[i][j] = INFINITY;
            }
        }
    }

    cout << "\nEnter the source node: ";
    cin >> v;

    dijkstra(n, v, cost, dist);

    cout << "\nShortest paths:\n";
    for (i = 1; i <= n; i++) {
        if (i != v) {
            cout << v << " to " << i << ": Distance = " << dist[i] << endl;
        }
    }
    cout << "\n\nName: Shovit Regmi\nRoll No: 32\n";
    return 0;
}
