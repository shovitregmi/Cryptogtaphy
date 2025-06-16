#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A structure to represent an item
struct Item {
    int value;
    int weight;
    float ratio;  // value/weight ratio
};

// Function to compare two items based on value/weight ratio
bool compare(const Item& a, const Item& b) {
    return a.ratio > b.ratio;  // Sort in descending order
}

// Function to calculate the maximum value of the knapsack
float fractionalKnapsack(int capacity, vector<Item>& items, int itemCount) {
    // Sort items based on value-to-weight ratio in decreasing order
    sort(items.begin(), items.end(), compare);

    int currentWeight = 0;  // Current weight in the knapsack
    float totalValue = 0.0f;  // Total value accumulated

    // Loop through all items
    for (int i = 0; i < itemCount; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take the whole item if it fits in the knapsack
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fractional part of the item
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * (float(remainingWeight) / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int itemCount, capacity;

    // Input the number of items and the capacity of the knapsack
    cout << "Enter the number of items: ";
    cin >> itemCount;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    // Create a vector to store items
    vector<Item> items(itemCount);

    // Input the value and weight for each item
    for (int i = 0; i < itemCount; i++) {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
        // Calculate the value-to-weight ratio for each item
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Call the fractionalKnapsack function and display the result
    float maxValue = fractionalKnapsack(capacity, items, itemCount);
    cout << "Maximum value in the knapsack = " << maxValue << endl;

    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}
