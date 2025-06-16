#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF 99999
#define N 4

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};

vector<vector<int>> dp(1 << N, vector<int>(N, -1));
vector<vector<int>> path(1 << N, vector<int>(N, -1));

int tsp(int mask, int pos)
{
    if (mask == (1 << N) - 1)
    {
        return dist[pos][0];
    }

    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    int ans = INF;
    int bestCity = -1;

    for (int city = 0; city < N; city++)
    {
        if (!(mask & (1 << city)))
        {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newAns < ans)
            {
                ans = newAns;
                bestCity = city;
            }
        }
    }

    path[mask][pos] = bestCity;
    return dp[mask][pos] = ans;
}

void printPath()
{
    int mask = 1;
    int pos = 0;
    cout << "Shortest path: ";
    cout << "1 ";

    while (mask != (1 << N) - 1)
    {
        int nextCity = path[mask][pos];
        cout << "-> " << nextCity + 1 << " ";
        mask |= (1 << nextCity);
        pos = nextCity;
    }
    cout << endl;
}

int main()
{
    cout << "The minimum cost is " << tsp(1, 0) << endl;

    printPath();

    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";
    return 0;
}
