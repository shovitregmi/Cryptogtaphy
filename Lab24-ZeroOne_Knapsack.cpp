#include <iostream>
#include <vector>
using namespace std;

// Function to compute the maximum value that can be obtained
int knapsack(int capacity, const vector<int> &weights, const vector<int> &values, int itemCount)
{
    vector<vector<int>> dp(itemCount + 1, vector<int>(capacity + 1, 0));

    // Build the dp table in a bottom-up manner
    for (int i = 1; i <= itemCount; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[itemCount][capacity]; // Maximum value that can be obtained
}

int main()
{
    int itemCount, capacity;

    cout << "Enter the number of items: ";
    cin >> itemCount;

    vector<int> values(itemCount), weights(itemCount);

    cout << "Enter the values of the items:\n";
    for (int i = 0; i < itemCount; i++)
    {
        cout << "Value of item " << i + 1 << ": ";
        cin >> values[i];
    }

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < itemCount; i++)
    {
        cout << "Weight of item " << i + 1 << ": ";
        cin >> weights[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "Maximum value in the knapsack: " << knapsack(capacity, weights, values, itemCount) << endl;
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}
