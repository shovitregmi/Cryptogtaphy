#include <iostream>
using namespace std;

int binarySearch(int a[], int l, int r, int key) {
    int m;
    if (l <= r) {
        m = (l + r) / 2;
        if (a[m] == key) {
            return m;
        } else if (key < a[m]) {
            return binarySearch(a, l, m - 1, key);
        } else {
            return binarySearch(a, m + 1, r, key);
        }
    }
    return -1;
}

int main() {
    int n, key, location;
    cout << "Enter the size of the list: ";
    cin >> n;

    int a[n];
    cout << "\nEnter the contents of the list: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "\nEnter the element to find in array: ";
    cin >> key;

    location = binarySearch(a, 0, n - 1, key);

    if (location == -1) {
        cout << "\n" << key << " is not in the list" << endl;
    } else {
        cout << key << " is in the index " << location << " of the array" << endl;
    }

    cout << "\n\nName: Shovit Regmi" << endl;
    cout << "Roll No: 32" << endl;

    return 0;
}
