#include <iostream>
#include <vector>
using namespace std;

void knapsack(const vector<int> &weights, const vector<int> &values, int n, int capacity,
              int currentIndex, int currentWeight, int currentValue, int &maxValue,
              vector<int> &includedItems, vector<int> &currentItems)
{

    if (currentWeight > capacity)
    {
        return;
    }

    if (currentValue > maxValue)
    {
        maxValue = currentValue;
        includedItems = currentItems;
    }

    for (int i = currentIndex; i < n; i++)
    {
        currentItems[i] = 1;
        knapsack(weights, values, n, capacity, i + 1, currentWeight + weights[i],
                 currentValue + values[i], maxValue, includedItems, currentItems);
        currentItems[i] = 0;
    }
}

int main()
{

    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n), values(n), includedItems(n, 0), currentItems(n, 0);

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    cout << "Enter the values of the items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int maxValue = 0;

    knapsack(weights, values, n, capacity, 0, 0, 0, maxValue, includedItems, currentItems);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    cout << "Items included in the knapsack:\n";
    for (int i = 0; i < n; i++)
    {
        if (includedItems[i])
        {
            cout << "Item " << (i + 1) << " (Weight: " << weights[i] << ", Value: " << values[i] << ")\n";
        }
    }
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}
