#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& a, int n) {
    int temp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (n - i - 1); ++j) {
            if (a[j] > a[j + 1]) {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
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

    bubbleSort(a, n);

    cout << "Data after sorting: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "\nName: Shovit Regmi\n";
    cout << "Roll No: 32\n";

    return 0;
}
