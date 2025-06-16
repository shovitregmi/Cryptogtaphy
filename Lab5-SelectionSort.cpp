#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& a, int n) {
    int temp, min;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
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

    selectionSort(a, n);

    cout << "\nData after sorting: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "\nName: Shovit Regmi\n";
    cout << "Roll No: 32\n";

    return 0;
}
