#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Overflow na ho iske liye
    long long int MOD = 1000000007;

    // Using Recursion
    int solveUsingRecursion(int n, int k, int target)
    {
        // Base Case
        if (target == 0 && n == 0)
        {
            return 1;
        }
        if (target != 0 && n == 0)
        {
            return 0;
        }
        if (target == 0 && n != 0)
        {
            return 0;
        }

        int ans = 0;
        // Explore All Possible Ways Pattern
        for (int i = 1; i <= k; i++)
        {
            // RC
            ans += solveUsingRecursion(n - 1, k, target - i);
        }
        return ans;
    }

    // Using Memoisation
    int solveUsingMem(int n, int k, int target, vector<vector<int>> &dp)
    {
        if (target == 0 && n == 0)
        {
            return 1;
        }
        if (target != 0 && n == 0)
        {
            return 0;
        }
        if (target == 0 && n != 0)
        {
            return 0;
        }

        if (dp[n][target] != -1)
        {
            return dp[n][target];
        }

        int ans = 0;
        // Explore All Possible Ways Pattern
        for (int i = 1; i <= k; i++)
        {
            // RC
            int recKaAns = 0;
            if (target - i >= 0)
                recKaAns = (solveUsingMem(n - 1, k, target - i, dp)) % MOD;
            ans = (ans % MOD + recKaAns % MOD) % MOD;
        }
        dp[n][target] = ans;
        return dp[n][target];
    }
    // Using Tabulation
    // int solveUsingTab(int n, int k, int target)
    // {
    //     vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    // }

    // WAY 2 Simple Understanding
    int solveUsingRecursionWayTWO(int n, int k, int target, int diceUsed, int currSum)
    {
        if (diceUsed == n && currSum == target)
        {
            return 1;
        }
        if (diceUsed == n && currSum != target)
        {
            // Ans Not Possible
            return 0;
        }
        if (currSum == target && diceUsed != n)
        {
            // Ans Not Possible
            return 0;
        }

        int ans = 0;
        for (int face = 1; face <= k; face++)
        {
            ans = ans + solveUsingRecursionWayTWO(n, k, target, diceUsed + 1, currSum + face);
        }
        return ans;
    }

    // Using Memoisation Way 2
    // Using Memoisation
    int solveUsingMemTWO(int n, int k, int target, int diceUsed, int currSum, vector<vector<int>> &dp)
    {
        if (diceUsed == n && currSum == target)
        {
            return 1;
        }
        if (diceUsed == n && currSum != target)
        {
            // Ans Not Possible
            return 0;
        }
        if (currSum == target && diceUsed != n)
        {
            // Ans Not Possible
            return 0;
        }

        if (dp[diceUsed][currSum] != -1)
        {
            return dp[diceUsed][currSum];
        }

        int ans = 0;
        for (int face = 1; face <= k; face++)
        {
            int recKaAns = 0;
            if (currSum + face <= target)
            {
                recKaAns = solveUsingMemTWO(n, k, target, diceUsed + 1, currSum + face, dp);
            }
            ans = (ans % MOD + recKaAns % MOD) % MOD;
        }
        dp[diceUsed][currSum] = ans;
        return dp[diceUsed][currSum];
    }

    // Using Tabulation
    int solveUsingTabTWO(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[n][target] = 1;

        for (int dice = n - 1; dice >= 0; dice--)
        {
            for (int sum = target; sum >= 0; sum--)
            {
                int ans = 0;
                for (int face = 1; face <= k; face++)
                {
                    int recKaAns = 0;
                    if (sum + face <= target)
                    {
                        recKaAns = dp[dice + 1][sum + face];
                    }
                    ans = (ans % MOD + recKaAns % MOD) % MOD;
                }
                dp[dice][sum] = ans;
            }
        }
        return dp[0][0];
    }

    // Space Optimisation
    int solveUsingTabTWOSpaceOptimisation(int n, int k, int target)
    {
        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        // Last wale row col me 1 dal dena
        next[target] = 1;

        for (int dice = n - 1; dice >= 0; dice--)
        {
            for (int sum = target; sum >= 0; sum--)
            {
                int ans = 0;
                for (int face = 1; face <= k; face++)
                {
                    int recKaAns = 0;
                    if (sum + face <= target)
                    {
                        recKaAns = next[sum + face];
                    }
                    ans = (ans % MOD + recKaAns % MOD) % MOD;
                }
                curr[sum] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int numRollsToTarget(int n, int k, int target)
    {

        // Using Recursion
        // int ans = solveUsingRecursion(n, k, target);

        // // Using Memoisation
        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // int ans = solveUsingMem(n, k, target, dp);

        // Using Tabulation
        // int ans = solveUsingTab(n, k, target);

        // ******WAY WAY APPROACH 2 ******//
        // WAY 2 Simple Understanding
        int diceUsed = 0;
        int currSum = 0;
        // Using Recursion
        // int ans = solveUsingRecursionWayTWO(n, k, target, diceUsed, currSum);

        // // Using Memoisation
        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // int ans = solveUsingMemTWO(n, k, target, diceUsed, currSum, dp);

        // Using Tabulation
        // int ans = solveUsingTabTWO(n, k, target);

        // Space Optimisation
        int ans = solveUsingTabTWOSpaceOptimisation(n, k, target);
        // ******End here****** //
        return ans;
    }
};

int main()
{
    Solution solution;

    int n, k, target;
    cout << "Enter the number of dice (n): ";
    cin >> n;
    cout << "Enter the number of faces on each die (k): ";
    cin >> k;
    cout << "Enter the target sum (target): ";
    cin >> target;

    int result = solution.numRollsToTarget(n, k, target);
    cout << "Number of ways to roll " << n << " dice with " << k
         << " faces to get the target sum " << target << " is: " << result << endl;

    return 0;
}