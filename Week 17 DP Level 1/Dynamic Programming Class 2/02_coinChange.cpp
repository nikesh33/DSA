#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solveUsingRecursion(vector<int> &coins, int amount)
    {
        // Base Case
        if (amount == 0)
        {
            return 0;
        }

        // Recursive Relation
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            // find ans using ith coin
            // int recursionKaAns = 0;
            // call recusrion only for valid amount i.e >= 0 wala amount
            if (amount - coins[i] >= 0)
            {
                int recursionKaAns =
                    solveUsingRecursion(coins, amount - coins[i]);
                //    if  a valid answer
                if (recursionKaAns != INT_MAX)
                {
                    // considering usage of ith coin
                    int ans = 1 + recursionKaAns;
                    mini = min(mini, ans);
                }
            }
        }
        return mini;
    }

    int solveUsingMem(vector<int> &coins, int amount, vector<int> &dp)
    {
        // Base Case
        if (amount == 0)
        {
            return 0;
        }

        // already ans exist
        if (dp[amount] != -1)
        {
            return dp[amount];
        }

        // Recursive Relation
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            // find ans using ith coin
            // int recursionKaAns = 0;
            // call recusrion only for valid amount i.e >= 0 wala amount
            if (amount - coins[i] >= 0)
            {
                int recursionKaAns =
                    solveUsingMem(coins, amount - coins[i], dp);
                //    if  a valid answer
                if (recursionKaAns != INT_MAX)
                {
                    // considering usage of ith coin
                    int ans = 1 + recursionKaAns;
                    mini = min(mini, ans);
                }
            }
        }
        // why we are doing this so that we dont have to process again the whole
        // process
        dp[amount] = mini;
        return dp[amount];
    }

    int solveUsingTabulation(vector<int> &coins, int amount)
    {
        // 1 Craete DP ARRAY
        int n = amount;
        vector<int> dp(n + 1, INT_MAX);

        // 2 Base case analayze and fill
        dp[0] = 0;

        // for loop
        for (int value = 1; value <= amount; value++)
        {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++)
            {

                if (value - coins[i] >= 0)
                {
                    int recursionKaAns = dp[value - coins[i]];

                    if (recursionKaAns != INT_MAX)
                    {

                        int ans = 1 + recursionKaAns;
                        mini = min(mini, ans);
                    }
                }
            }
            dp[value] = mini;
        }
        return dp[amount];
    }

    // NO OPTIMIZATION POSSIBLE IN THIS CASE KYUKI PURE ARRAY PE DEPEND HO RAHA In Worst CASE

    int coinChange(vector<int> &coins, int amount)
    {
        // int ans = solveUsingRecursion(coins, amount);
        // int n = amount;
        // vector<int> dp(n + 1, -1);
        // int ans = solveUsingMem(coins, amount, dp);

        int ans = solveUsingTabulation(coins, amount);
        if (ans == INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

int main()
{
    Solution sol;

    vector<int> coins = {1, 2, 5}; // Example set of coin denominations
    int amount = 18;               // Example amount to make

    int result = sol.coinChange(coins, amount);

    if (result != -1)
    {
        cout << "Minimum number of coins needed: " << result << endl;
    }
    else
    {
        cout << "It is not possible to make the given amount with the available coins." << endl;
    }

    return 0;
}