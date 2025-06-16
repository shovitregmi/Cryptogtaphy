#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long long modExp(long long base, long long exponent, long long modValue)
{
    long long res = 1;
    base = base % modValue;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            res = (res * base) % modValue;
        exponent = exponent >> 1;
        base = (base * base) % modValue;
    }
    return res;
}

bool millerCheck(long long factor, long long number)
{
    long long randNum = 2 + rand() % (number - 4);
    long long result = modExp(randNum, factor, number);
    if (result == 1 || result == number - 1)
        return true;
    while (factor != number - 1)
    {
        result = (result * result) % number;
        factor *= 2;
        if (result == 1)
            return false;
        if (result == number - 1)
            return true;
    }
    return false;
}

bool checkPrime(long long number, int iterations)
{
    if (number <= 1 || number == 4)
        return false;
    if (number <= 3)
        return true;
    long long factor = number - 1;
    while (factor % 2 == 0)
        factor /= 2;
    for (int i = 0; i < iterations; i++)
    {
        if (!millerCheck(factor, number))
            return false;
    }
    return true;
}

int main()
{

    long long numToCheck;
    int iterCount;

    cout << "Enter a number to check for primality: ";
    cin >> numToCheck;

    cout << "Enter the number of iterations (k): ";
    cin >> iterCount;

    if (checkPrime(numToCheck, iterCount))
    {
        cout << numToCheck << " is probably a prime number." << endl;
    }
    else
    {
        cout << numToCheck << " is not a prime number." << endl;
    }

    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}
