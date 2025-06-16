#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int n) {
    int temp, j;
    for (int i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int n;
    cout << "Enter the number of data items: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    insertionSort(a, n);

    cout << "\nData after sorting: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "\nName: Shovit Regmi\n";
    cout << "Roll No: 32\n";

    return 0;
}
