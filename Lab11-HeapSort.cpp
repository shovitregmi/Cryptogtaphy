#include <iostream>
using namespace std;

const int MAX = 100;

void heapSort(int A[], int n);
void buildMaxHeap(int A[], int n);
void maxHeapify(int A[], int i, int n);
void swap(int &a, int &b);

int main()
{
    int A[MAX], n;
    cout << "Enter the number of Data items: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    heapSort(A, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
    cout << "\n\nName: Shovit Regmi\n";
    cout << "Roll No: 32\n";
    return 0;
}

void heapSort(int A[], int n)
{
    buildMaxHeap(A, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(A[0], A[i]);
        maxHeapify(A, 0, i);
    }
}

void buildMaxHeap(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(A, i, n);
    }
}

void maxHeapify(int A[], int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i)
    {
        swap(A[i], A[largest]);
        maxHeapify(A, largest, n);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
