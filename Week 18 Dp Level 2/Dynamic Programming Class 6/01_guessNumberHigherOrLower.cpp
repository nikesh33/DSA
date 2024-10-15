#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Using Recursion
    int solveUsingRecursion(int start, int end)
    {
        // base case
        if (start >= end)
        {
            return 0;
        }
        // **** For Better UnderStanding of above base case **** //
        // if (start > end) {
        //     // range se bahar
        //     // zero penalty
        //     return 0;
        // }
        // if (start == end) {
        //     // Sirf 1 he number hai
        //     // it means zero penalty
        //     return 0;
        // }

        // for our MinAns
        int ans = INT_MAX;
        for (int i = start; i <= end; i++)
        {
            ans = min(ans, i + max(solveUsingRecursion(start, i - 1),
                                   solveUsingRecursion(i + 1, end)));
        }
        return ans;
    }

    // Using Memoisation
    int solveUsingMem(int start, int end, vector<vector<int>> &dp)
    {
        // base case
        if (start >= end)
        {
            return 0;
        }

        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }

        // for our MinAns
        int ans = INT_MAX;
        for (int i = start; i <= end; i++)
        {
            ans = min(ans, i + max(solveUsingMem(start, i - 1, dp),
                                   solveUsingMem(i + 1, end, dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }

    // Using Tabulation
    int solveUsingTabulation(int n)
    {
        // Note n+2
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

        for (int start_index = n - 1; start_index >= 1; start_index--)
        {
            for (int end_index = 1; end_index <= n; end_index++)
            {
                if (start_index >= end_index)
                {
                    // Invalid Range
                    continue; // use to skip
                }

                int ans = INT_MAX;
                for (int i = start_index; i <= end_index; i++)
                {
                    ans = min(ans, i + max(dp[start_index][i - 1], dp[i + 1][end_index]));
                }
                dp[start_index][end_index] = ans;
            }
        }
        return dp[1][n];
    }

    // // Space Optimisation NOT SOLVED 
    // int solveUsingTabulationSO(int n)
    // {
    //     // vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
    //     // 3 Array Needed
    //     vector<int>curr(n+1,0);
    //     vector<int>next1(n+1,0);
    //     vector<int>next2(n+2,0);

    //     for (int start_index = n - 1; start_index >= 1; start_index--)
    //     {
    //         for (int end_index = 1; end_index <= n; end_index++)
    //         {
    //             if (start_index >= end_index)
    //             {
    //                 // Invalid Range
    //                 continue; // use to skip
    //             }

    //             int ans = INT_MAX;
    //             for (int i = start_index; i <= end_index; i++)
    //             {
    //                 ans = min(ans, i + max(dp[start_index][i - 1], dp[i + 1][end_index]));
    //             }
    //             dp[start_index][end_index] = ans;
    //         }
    //     }
    //     return dp[1][n];
    // }

    int getMoneyAmount(int n)
    {
        // Solving Using Recursion
        int start = 1;
        int end = n;
        // int ans = solveUsingRecursion(start, end);

        // // Solving Using Memoisation
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // int ans = solveUsingMem(start, end, dp);

        // Solving Using Tabulation
        int ans = solveUsingTabulation(n);

        // // Space Optimisation
        // int ans = solveUsingTabulationSO(n);

        return ans;
    }
};

int main()
{
    Solution solution;
    int n;

    // Taking input from user for the value of n
    cout << "Enter the value of n: ";
    cin >> n;

    // Getting the minimum amount of money required to guarantee a win
    int result = solution.getMoneyAmount(n);

    // Output the result
    cout << "The minimum amount of money required to guarantee a win is: " << result << endl;

    return 0;
}
