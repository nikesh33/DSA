#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Plain Recursion
    int solveUsingRecursion(int n)
    {
        // Base Case
        if (n == 0 || n == 1)
        {
            return n;
        }
        // Recursive Relation
        int ans = solveUsingRecursion(n - 1) + solveUsingRecursion(n - 2);
        return ans;
    }

    // TOP-DOWN Recursion + Memoization
    int solveUsingMemoization(int n, vector<int> &dp)
    {
        // Base Case
        if (n == 0 || n == 1)
        {
            return n;
        }
        // Step 3-> Check if Ans already exist, then return ans
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // Recursive Relation
        // Step 2-> Store ans in DP Array
        dp[n] = solveUsingMemoization(n - 1, dp) + solveUsingMemoization(n - 2, dp);
        return dp[n];
    }

    // Bottom-UP Tabulation Method
    int solveUsingTabulation(int n)
    {
        // Using Tabulation 2->
        // Step 1-> Create DP Array
        vector<int> dp(n + 1, -1);

        // Step 2-> Analyse base case and fill DP Array
        dp[0] = 0;
        // EXTRA Case //Agar in Case aapne n ki value 0 di toh 0 size ka Array
        // ban jayega phir jab dp[1] =1 ; karoge to case fatt jayega
        if (n == 0)
        {
            return 0;
        }
        dp[1] = 1;

        // Step 3-> Fill the remaining DP Array
        // Dp Array ka SIZE = n+1
        // Index move from 0 to n
        // 0 and 1 index ko already fill kar liya hai
        // 2 index se n index tak abhi fill nahi hai
        for (int index = 2; index <= n; index++)
        {
            // Copy Paste Karo Recursive Logic Ko
            // Replace Recursive Call with DP Array
            // Make Sure DP Array is Using Looping Variable
            dp[index] = dp[index - 1] + dp[index - 2];
        }
        // Return Ans (Top-Down Ka Ans Dekh Liya AAPNE Jo Nikal Rahe the wahi
        // Return kardiya)
        return dp[n];
    }

    // Space Optimisation
    int solveUsingTabulationSpaceOptimised(int n)
    {
        int prev = 0;
        if (n == 0)
        {
            return 0;
        }

        int curr = 1;
        if (n == 1)
        {
            return 1;
        }

        int ans;
        for (int index = 2; index <= n; index++)
        {
            ans = curr + prev;
            // Prev and Curr ko ek step aage move karna
            prev = curr;
            curr = ans;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Using Recursion 1->
    // int ans = sol.solveUsingRecursion(n);
    //  return ans;

    // // Using Top-Down 2->
    // // Step 1-> Create A DP Array
    // vector<int> dp(n + 1, -1);
    // int ans = sol.solveUsingMemoization(n, dp);
    // return ans;

    // // Using Tabulation 3->
    // int ans = sol.solveUsingTabulation(n);
    // cout << "Fibonacci number for " << n << "th term is: " << ans << endl;

    // // Space Optimised 4->
    int ans = sol.solveUsingTabulationSpaceOptimised(n);
    cout << "Fibonacci number for " << n << "th term is: " << ans << endl;

    return 0;
}
