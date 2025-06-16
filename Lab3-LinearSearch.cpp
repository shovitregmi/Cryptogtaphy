#include <iostream>
using namespace std;

int linearSearch(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, key, location;
    cout << "Enter the size of the list: ";
    cin >> n;

    int a[n];
    cout << "\nEnter the contents of the list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "\nEnter the element to find in array: ";
    cin >> key;

    location = linearSearch(a, n, key);

    if (location == -1)
    {
        cout << "\n"
             << key << " is not in the list" << endl;
    }
    else
    {
        cout << key << " is in the index " << location << " of the array" << endl;
    }

    cout <<  "\n\nName: Shovit Regmi \nRoll No: 32" << endl;

    return 0;
}
