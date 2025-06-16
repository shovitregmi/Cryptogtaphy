#include <iostream>
using namespace std;

void findMinMax(int a[], int l, int r, int &min, int &max)
{
    int min1, max1, min2, max2;

    if (l == r)
    {
        min = a[l];
        max = a[l];
        return;
    }

    if (r == l + 1)
    {
        if (a[l] < a[r])
        {
            min = a[l];
            max = a[r];
        }
        else
        {
            min = a[r];
            max = a[l];
        }
        return;
    }

    int mid = (l + r) / 2;

    findMinMax(a, l, mid, min1, max1);
    findMinMax(a, mid + 1, r, min2, max2);

    min = (min1 < min2) ? min1 : min2;
    max = (max1 > max2) ? max1 : max2;
}

int main()
{
    int n, min, max;

    cout << "Enter the size of the list: ";
    cin >> n;

    int a[n]; // Array size based on input
    cout << "\nEnter the contents of the list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    findMinMax(a, 0, n - 1, min, max);

    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    cout << "\n\nName: Shovit Regmi" << endl;
    cout << "Roll No: 32" << endl;

    return 0;
}
