#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

int modularInverse(int num, int mod)
{
    int modOriginal = mod, quotient, temp;
    int inversePrev = 0, inverseCurr = 1;

    if (mod == 1)
        return 0;

    while (num > 1)
    {
        quotient = num / mod;
        temp = mod;
        mod = num % mod;
        num = temp;

        temp = inversePrev;
        inversePrev = inverseCurr - quotient * inversePrev;
        inverseCurr = temp;
    }

    return (inverseCurr < 0) ? inverseCurr + modOriginal : inverseCurr;
}

int chineseRemainder(int moduli[], int remainders[], int numEquations)
{
    int totalProduct = 1, solution = 0;

    for (int i = 0; i < numEquations; i++)
        totalProduct *= moduli[i];

    for (int i = 0; i < numEquations; i++)
    {
        int partialProduct = totalProduct / moduli[i];
        solution += remainders[i] * modularInverse(partialProduct, moduli[i]) * partialProduct;
    }

    return solution % totalProduct;
}

int main()
{

    int moduli[10], remainders[10], numEquations;

    cout << "Enter the number of modular equations: ";
    cin >> numEquations;

    cout << "Enter values for 'remainder' and 'modulus' (x = remainder (mod modulus)):" << endl;
    for (int i = 0; i < numEquations; i++)
    {
        cout << "Equation " << i + 1 << ": ";
        cin >> remainders[i] >> moduli[i];
    }   

    int result = chineseRemainder(moduli, remainders, numEquations);
    cout << "The smallest x satisfying all given congruences is: " << result << endl;
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}
