#include <iostream>
#define MAX 100

using namespace std;

int Select_NonLinear(int a[], int k, int n) {
    int i, j, temp, min;
    for (i = 0; i < k;  i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    return a[k - 1];
}

int main() {
    int a[MAX], n, i, k, kthSmallest;
    cout << "Enter the number of Data items: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (i = 0; i < n; ++i)
        cin >> a[i];

    cout << "Enter the position to find: ";
    cin >> k;

    kthSmallest = Select_NonLinear(a, k, n);
    cout << k << "th smallest: " << kthSmallest << endl;

    cout << "\nName: Shovit Regmi";
    cout << "\nRoll No: 32" << endl;

    return 0;
}
