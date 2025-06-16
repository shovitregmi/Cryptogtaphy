#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main()
{

    int n;
    cout << "Enter the position of Fibonacci number to compute: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Position must be a non-negative integer." << endl;
        return 1;
    }

    memo.assign(n + 1, -1);

    cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << endl;
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}
