#include <iostream>
using namespace std;

const int MAX = 100;

void quick_sort(int a[], int l, int r);
int partition(int a[], int l, int r);

int main()
{
    int a[MAX], n;
    cout << "Enter the number of Data items: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    cout << "\nData after sorting: ";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n\nName: Shovit Regmi\n";
    cout << "Roll No: 18\n";
    return 0;
}

void quick_sort(int a[], int l, int r)
{
    int j;
    if (l < r)
    {
        j = partition(a, l, r);
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, r);
    }
}

int partition(int a[], int l, int r)
{
    int pivot, i, j, temp;
    pivot = a[l];
    i = l;

    for (j = l + 1; j <= r; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }

    temp = a[l];
    a[l] = a[i];
    a[i] = temp;
    return i;
}
