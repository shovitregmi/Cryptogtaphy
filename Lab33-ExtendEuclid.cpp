#include <iostream>
using namespace std;

int extendedGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main()
{
    int a, b, x, y;
    cout << "Enter two integers: ";
    cin >> a >> b;

    int gcd = extendedGCD(a, b, x, y);

    cout << "The GCD of " << a << " and " << b << " is " << gcd << endl;
    cout << "Coefficients x and y are " << x << " and " << y << ", respectively." << endl;
    cout << "Verification: " << a << " * " << x << " + " << b << " * " << y << " = " << gcd << endl;
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}
