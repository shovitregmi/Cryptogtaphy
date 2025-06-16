#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 100;

void Randomised_QS(int[], int, int);
int Randomised_partition(int[], int, int);
int partition(int[], int, int);

int main()
{
    int a[MAX], n;

    cout << "Enter the number of Data items: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    Randomised_QS(a, 0, n - 1);

    cout << "\nData after sorting: ";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n\nName: Shovit Regmi\n";
    cout << "Roll No: 32\n";
    return 0;
}

void Randomised_QS(int a[], int l, int r)
{
    int j;
    if (l < r)
    {
        j = Randomised_partition(a, l, r);
        Randomised_QS(a, l, j - 1);
        Randomised_QS(a, j + 1, r);
    }
}
int Randomised_partition(int a[], int l, int r)
{
    int k, temp;
    srand(time(0));               // using `time(0)` instead of `time(NULL)` for clarity
    k = rand() % (r - l + 1) + l; // Random index between l and r
    temp = a[k];
    a[k] = a[l];
    a[l] = temp;
    return partition(a, l, r);
}
int partition(int a[], int l, int r)
{
    int pivot, i, j, temp;
    pivot = a[l];
    i = l;
    for (j = i + 1; j <= r; j++)
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
