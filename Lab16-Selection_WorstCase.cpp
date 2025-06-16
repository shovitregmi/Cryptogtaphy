#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& a, int left, int right);
int selectPivot(vector<int>& a, int left, int right);
int medianOfMedians(vector<int>& a, int left, int right);
int Select(vector<int>& a, int left, int right, int k);
void swap(vector<int>& a, int i, int j);

int main() {
    int n, k, kthSmallest;
    cout << "Enter the number of data items: ";
    cin >> n;
    
    vector<int> a(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << "Enter the position to find (1-based): ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid value for k. It should be between 1 and " << n << ".\n";
        return 1;
    }

    kthSmallest = Select(a, 0, n - 1, k);
    cout << k << "th smallest element: " << kthSmallest << endl;

    cout << "\n\nName: Shovit Regmi\nRoll No: 32\n";
    return 0;
}

int Select(vector<int>& a, int left, int right, int k) {
    if (left == right)
        return a[left];  

    int pivot = medianOfMedians(a, left, right);
    int pivotIndex = partition(a, left, right);

    int num_elements_in_left = pivotIndex - left + 1;

    if (k == num_elements_in_left)
        return a[pivotIndex];
    else if (k < num_elements_in_left)
        return Select(a, left, pivotIndex - 1, k);
    else
        return Select(a, pivotIndex + 1, right, k - num_elements_in_left);
}

int partition(vector<int>& a, int left, int right) {
    int pivot = a[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a, i, j);
        }
    }

    swap(a, i + 1, right);
    return i + 1;
}

void swap(vector<int>& a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int medianOfMedians(vector<int>& a, int left, int right) {
    int size = right - left + 1;

    if (size <= 5) {
        return selectPivot(a, left, right);
    }

    for (int i = left; i <= right; i += 5) {
        int subRight = min(i + 4, right);
        int median = selectPivot(a, i, subRight);
        swap(a, left + (i - left) / 5, median);
    }

    return Select(a, left, left + (size / 5) - 1, (size / 10) + 1);
}

int selectPivot(vector<int>& a, int left, int right) {
    int n = right - left + 1;
    if (n <= 5) {
        sort(a.begin() + left, a.begin() + right + 1);
        return (left + right) / 2;
    }
    return (left + right) / 2;
}
