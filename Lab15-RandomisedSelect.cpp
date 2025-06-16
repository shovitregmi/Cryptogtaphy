#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 100

using namespace std;

int Randomised_Select(int[], int, int, int);
int Randomised_partition(int[], int, int);
int partition(int[], int, int);

int main() {
    int a[MAX], n, i, k, kthSmallest;
    
    cout << "Enter the number of Data items: ";
    cin >> n;
    
    cout << "Enter the elements: ";
    for (i = 0; i < n; ++i)
        cin >> a[i];
    
    cout << "Enter the position to find: ";
    cin >> k;
    
    if (k < 1 || k > n) {
        cout << "Invalid input for k. It should be between 1 and " << n << endl;
        return 1;
    }
    
    kthSmallest = Randomised_Select(a, 0, n - 1, k);
    cout << k << "th smallest element: " << kthSmallest << endl;

    cout << "\nName: Shovit Regmi";
    cout << "\nRoll No: 32" << endl;
    
    return 0;
}
int Randomised_Select(int a[], int l, int r, int i) {
    if (l == r)
        return a[l];

    int p = Randomised_partition(a, l, r);
    int k = p - l + 1;

    if (i == k)
        return a[p];
    else if (i < k)
        return Randomised_Select(a, l, p - 1, i);
    else
        return Randomised_Select(a, p + 1, r, i - k);
}
int Randomised_partition(int a[], int l, int r) {
    srand(time(NULL));
    int k = rand() % (r - l + 1) + l;
    
    swap(a[k], a[l]);  
    return partition(a, l, r);
}
int partition(int a[], int l, int r) {
    int pivot = a[l];
    int i = l;

    for (int j = l + 1; j <= r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[l], a[i]);
    return i;
}
