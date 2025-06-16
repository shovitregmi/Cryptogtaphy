#include <iostream>
using namespace std;

void findMinMax(int a[], int n, int &min, int &max) {
    min = a[0];
    max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
        if (a[i] > max) {
            max = a[i];
        }
    }
}

int main() {
    int n, min, max;

    cout << "Enter the size of the list: ";
    cin >> n;

    int a[n]; // Array size based on input
    cout << "\nEnter the contents of the list: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    findMinMax(a, n, min, max);
    
    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    cout << "\n\nName: Shovit Regmi" << endl;
    cout << "Roll No: 32" << endl;

    return 0;
}
