#include <iostream>
#include <vector>
using namespace std;

// // USING ONLY RECURSION
// class Solution {
// public:
//     int fib(int n) {
//         // base case - mandatory
//         // processing - optional
//         // recursive relation - mandatory

//         // base case
//         if (n == 0 || n == 1) {
//             return n;
//         }

//         // rec relation
//         int ans = fib(n - 1) + fib(n - 2);
//         return ans;
//     }
// };

// USING -> (DP) TOP-DOWN APPROACH -> MEMOIZATION
class Solution
{
public:
    int solveUsingMem(int n, vector<int> &dp)
    {
        // Base case
        if (n == 0 || n == 1)
        {
            return n;
        }
        // Step 3: If ans Already Exist then return ans
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // Step 2: Store and return Dp ARRAY
        dp[n] = solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp);
        return dp[n];
    }

    int fib(int n)
    {
        // Step 1: Create Dp ARRAY
        vector<int> dp(n + 1, -1);

        int ans = solveUsingMem(n, dp);
        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = sol.fib(n);
    cout << "Fibonacci number for " << n << " is: " << result << endl;

    return 0;
}