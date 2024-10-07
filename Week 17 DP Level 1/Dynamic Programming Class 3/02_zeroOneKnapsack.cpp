#include <iostream>
#include <vector>
using namespace std;

// Using Recursion
int solveUsingRecursion(int capacity, int wt[], int profit[], int index, int n)
{
    // Base Case
    if (index == n - 1)
    {
        if (wt[index] <= capacity)
        {
            return profit[index];
        }
        else
        {
            return 0;
        }
    }

    // inclusion exclusion
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingRecursion(capacity - wt[index], wt, profit, index + 1, n);
    }
    int exclude = 0 + solveUsingRecursion(capacity, wt, profit, index + 1, n);
    int ans = max(include, exclude);
    return ans;
}

// Using Memoisation
int solveUsingMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int>> &dp)
{
    // Base Case
    if (index == n - 1)
    {
        if (wt[index] <= capacity)
        {
            return profit[index];
        }
        else
        {
            return 0;
        }
    }

    if (dp[capacity][index] != -1)
    {
        return dp[capacity][index];
    }

    // inclusion exclusion
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingMem(capacity - wt[index], wt, profit, index + 1, n, dp);
    }
    int exclude = 0 + solveUsingMem(capacity, wt, profit, index + 1, n, dp);
    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}

// Uisng Tabulation
int solveUsingTab(int capacity, int wt[], int profit[], int index, int n)
{
    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));

    for (int row = 0; row <= capacity; row++)
    {
        dp[row][n] = 0;
    }

    for (int i = 0; i <= capacity; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            // include / exc
            int include = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + dp[i - wt[j]][j + 1];
            }
            int exclude = 0 + dp[i][j + 1];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[capacity][0];
}

// Space Optimisation
int solveUsingTabSO(int capacity, int wt[], int profit[], int index, int n)
{
    // No need of 2D vector in SO
    // vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
    vector<int> next(capacity + 1, -1);
    vector<int> curr(capacity + 1, -1);

    for (int row = 0; row <= capacity; row++)
    {
        // dp[row][n] = 0;
        next[row] = 0;
    }

    for (int j = n - 1; j >= 0; j--)
    {

        for (int i = 0; i <= capacity; i++)
        {
            // include / exc
            int include = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + next[i - wt[j]];
            }
            int exclude = 0 + next[i];
            curr[i] = max(include, exclude);
        }
        // shift
        next = curr;
    }
    return curr[capacity];
}

// Space Optimisation 2
int solveUsingTabSO2(int capacity, int wt[], int profit[], int index, int n)
{
    // No need of 2D vector in SO
    // vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
    vector<int> next(capacity + 1, -1);
    // vector<int> curr(capacity + 1, -1);

    for (int row = 0; row <= capacity; row++)
    {
        // dp[row][n] = 0;
        next[row] = 0;
    }

    for (int j = n - 1; j >= 0; j--)
    {

        for (int i = capacity; i >= 0; i--)
        {
            // include / exc
            int include = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + next[i - wt[j]];
            }
            int exclude = 0 + next[i];
            next[i] = max(include, exclude);
        }
        // No need shifting because we only have 1 array in this
        // next = next;
    }
    return next[capacity];
}

int main()
{
    int capacity = 6;
    int wt[] = {1, 2, 3};
    int profit[] = {10, 15, 40};
    int index = 0;
    int n = 3;

    // // Using Recursion
    // int ans = solveUsingRecursion(capacity, wt, profit, index, n);
    // cout << "Max Profit: " << ans << endl;

    // // Using Memoisation
    // // Create 2D Vector
    // vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));

    // int ans = solveUsingMem(capacity, wt, profit, index, n, dp);
    // cout << "Max Profit: " << ans << endl;
    // // vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));

    // // Using Tabulation
    // int ans = solveUsingTab(capacity, wt, profit, index, n);
    // cout << "Max Profit: " << ans << endl;

    // // Space Optimisation
    // int ans = solveUsingTabSO(capacity, wt, profit, index, n);
    // cout << "Max Profit: " << ans << endl;

    // Space Optimisation 2
    int ans = solveUsingTabSO2(capacity, wt, profit, index, n);
    cout << "Max Profit: " << ans << endl;

    return 0;
}