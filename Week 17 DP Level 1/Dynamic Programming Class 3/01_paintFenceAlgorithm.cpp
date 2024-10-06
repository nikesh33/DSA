#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int n, int k)
{
    // Base Case
    if (n == 1)
    {
        return k;
    }

    if (n == 2)
    {
        return (k + k * (k - 1));
    }

    int ans = (solveUsingRecursion(n - 1, k) + solveUsingRecursion(n - 2, k)) * (k - 1);
    return ans;
}

int solveUsingMem(int n, int k, vector<int> &dp)
{
    // Base Case
    if (n == 1)
    {
        return k;
    }

    if (n == 2)
    {
        return (k + k * (k - 1));
    }

    // already exist
    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (solveUsingMem(n - 1, k, dp) + solveUsingMem(n - 2, k, dp)) * (k - 1);
    return dp[n];
}

// Tabulation
int solveUsingTabulation(int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = k + k * (k - 1);

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
    }
    return dp[n];
}

// Space Optimisation
int solveUsingTabulationSpaceOptimisation(int n, int k)
{
    // vector<int> dp(n + 1, -1);
    int prev2 = k;
    int prev1 = k + k * (k - 1);
    int curr;

    for (int i = 3; i <= n; i++)
    {
        curr = (prev1 + prev2) * (k - 1);
        // Shift
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main()
{
    // Number of Post
    int n = 3;
    // Number of Colors
    int k = 3;

    // Using Recursion
    // int ans = solveUsingRecursion(n, k);
    // cout << "Ans: " << ans << endl;

    // // Using Memoization
    // vector<int> dp(n + 1, -1);
    // int ans = solveUsingMem(n, k, dp);
    // cout << "Ans: " << ans << endl;

    // // Using Tabulation
    // int ans = solveUsingTabulation(n, k);
    // cout << "Ans of Tabulation: " << ans << endl;

    // Space Optimisation
    int ans = solveUsingTabulationSpaceOptimisation(n, k);
    cout << "Ans of Space Optimisation: " << ans << endl;

    return 0;
}