#include <iostream>
using namespace std;

void generateFibonacci(int n)
{
    int t1 = 0, t2 = 1, nextTerm;

    cout << "Fibonacci Sequence: " << t1 << ", " << t2;

    for (int i = 3; i <= n; ++i)
    {
        nextTerm = t1 + t2;
        cout << ", " << nextTerm;
        t1 = t2;
        t2 = nextTerm;
    }
}

int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    if (n < 1)
    {
        cout << "Please enter a positive integer." << endl;
    }
    else if (n == 1)
    {
        cout << "Fibonacci Sequence: 0" << endl;
    }
    else
    {
        generateFibonacci(n);
    }

    cout << "\n\nName: Shovit Regmi \nRoll No: 32\n" << endl;

    return 0;
}
