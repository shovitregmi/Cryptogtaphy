#include <iostream>
#include <vector>
using namespace std;

void printSubset(const vector<int> &subset)
{
    cout << "{ ";
    for (int num : subset)
    {
        cout << num << " ";
    }
    cout << "}\n";
}

void findSubsetsWithSum(const vector<int> &arr, int n, int targetSum, vector<int> &subset)
{
    if (targetSum == 0)
    {
        printSubset(subset);
        return;
    }

    if (n == 0 || targetSum < 0)
    {
        return;
    }

    findSubsetsWithSum(arr, n - 1, targetSum, subset);

    subset.push_back(arr[n - 1]);
    findSubsetsWithSum(arr, n - 1, targetSum - arr[n - 1], subset);
    subset.pop_back();
}

int main()
{

    int n, targetSum;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> targetSum;

    vector<int> subset;
    cout << "Subsets with the given sum are:\n";
    findSubsetsWithSum(arr, n, targetSum, subset);
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}
