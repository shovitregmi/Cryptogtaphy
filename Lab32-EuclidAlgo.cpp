#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{

    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "The GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}
