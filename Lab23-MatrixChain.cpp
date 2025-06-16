#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to compute the minimum number of multiplications needed
int matrixChainOrder(const vector<int> &p, int n)
{
    vector<vector<int>> m(n, vector<int>(n, 0)); // m[i][j] will store the minimum number of scalar multiplications
    int q;

    // Initialize the diagonal of m with 0, as a single matrix requires no multiplication
    for (int i = 1; i < n; ++i)
    {
        m[i][i] = 0;
    }

    // l is the chain length
    for (int l = 2; l < n; ++l)
    {
        for (int i = 1; i < n - l + 1; ++i)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            // Find the minimum cost of multiplying matrices i through j
            for (int k = i; k < j; ++k)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n -  1];
}

int main()
{
    int n;
    cout << "Enter the number of matrices (n): ";
    cin >> n;

    vector<int> p(n);
    cout << "Enter the dimensions of matrices (p[i-1] x p[i] for matrix Ai):" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "p[" << i << "]: ";
        cin >> p[i];
    }

    cout << "Minimum number of multiplications is: " << matrixChainOrder(p, n) << endl;
    cout << "\nName: Shovit Regmi\nRoll No.: 32" << endl;

    return 0;
}
