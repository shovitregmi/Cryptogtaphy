#include <iostream>
using namespace std;

const int MAX = 100;

void mergeSort(int a[], int l, int h);
void merge(int a[], int l, int m, int h);

void mergeSort(int a[], int l, int h)
{
    int m;
    if (l < h)
    {
        m = (l + h) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, h);
        merge(a, l, m, h);
    }
}

void merge(int a[], int l, int m, int h)
{
    int i, j, k, temp[MAX];
    i = l;
    j = m + 1;
    k = l;
    while (i <= m && j <= h)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= m)
        temp[k++] = a[i++];
    while (j <= h)
        temp[k++] = a[j++];
    for (i = l; i <= h; i++)
        a[i] = temp[i];
}

int main()
{
    int a[MAX], n;
    cout << "Enter the number of Data items: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    mergeSort(a, 0, n - 1);
    cout << "\nData after sorting: ";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n\nName: Shovit Regmi\n";
    cout << "Roll No: 32\n";
    return 0;
}
