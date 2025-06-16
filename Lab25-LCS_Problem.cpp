#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to find the length of the longest common subsequence
int lcs(const string &X, const string &Y)
{
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp table in bottom-up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n]; // The length of LCS
}

int main()
{
    string X, Y;

    cout << "Enter first sequence: ";
    cin >> X;

    cout << "Enter second sequence: ";
    cin >> Y;

    cout << "Length of Longest Common Subsequence: " << lcs(X, Y) << endl;
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";

    return 0;
}
