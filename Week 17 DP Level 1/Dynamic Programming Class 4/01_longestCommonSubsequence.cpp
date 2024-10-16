#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Using Recursion
    int solveUsingRecursion(string text1, string text2, int i, int j)
    {
        // Base Case
        if (i >= text1.length())
        {
            return 0;
        }
        if (j >= text2.length())
        {
            return 0;
        }

        // recursive call
        int ans = 0;
        if (text1[i] == text2[j])
        {
            ans = 1 + solveUsingRecursion(text1, text2, i + 1, j + 1);
        }
        else
        {
            ans = 0 + max(solveUsingRecursion(text1, text2, i, j + 1),
                          solveUsingRecursion(text1, text2, i + 1, j));
        }
        return ans;
    }

    // Using Memoisation
    int solveUsingMem(string &text1, string &text2, int i, int j,
                      vector<vector<int>> &dp)
    {
        // Base Case
        if (i >= text1.length())
        {
            return 0;
        }
        if (j >= text2.length())
        {
            return 0;
        }

        // already exist case
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // recursive call
        int ans = 0;
        if (text1[i] == text2[j])
        {
            dp[i][j] = 1 + solveUsingMem(text1, text2, i + 1, j + 1, dp);
        }
        else
        {
            dp[i][j] = 0 + max(solveUsingMem(text1, text2, i, j + 1, dp),
                               solveUsingMem(text1, text2, i + 1, j, dp));
        }
        return dp[i][j];
    }

    // Using Tabulation
    int solveUsingTab(string a, string b)
    {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

        for (int i_index = a.length() - 1; i_index >= 0; i_index--)
        {
            for (int j_index = b.length() - 1; j_index >= 0; j_index--)
            {
                int ans = 0;
                if (a[i_index] == b[j_index])
                {
                    ans = 1 + dp[i_index + 1][j_index + 1];
                }
                else
                {
                    ans = 0 + max(dp[i_index][j_index + 1],
                                  dp[i_index + 1][j_index]);
                }
                dp[i_index][j_index] = ans;
            }
        }
        return dp[0][0];
    }

    // Space Optimisation (col wise)
    int solveUsingTabSO(string a, string b)
    {
        // WE Dont Need Entire 2D Vector
        // vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
        // To go column wise it will a.length
        vector<int> curr(a.length() + 1, 0);
        vector<int> next(a.length() + 1, 0);

        for (int j_index = b.length() - 1; j_index >= 0; j_index--)
        {
            for (int i_index = a.length() - 1; i_index >= 0; i_index--)
            {
                int ans = 0;
                if (a[i_index] == b[j_index])
                {
                    ans = 1 + next[i_index + 1];
                }
                else
                {
                    ans = 0 + max(next[i_index],
                                  curr[i_index + 1]);
                }
                curr[i_index] = ans;
            }
            // Shifting
            next = curr;
        }
        return next[0];
    }

    // Space Optimisation But Without Changing Loop (row Wise)
    int solveUsingTabSONoLoopChange(string a, string b)
    {
        // To go row wise it will b.length
        vector<int> currRow(b.length() + 1, 0);
        vector<int> nextRow(b.length() + 1, 0);

        for (int i_index = a.length() - 1; i_index >= 0; i_index--)
        {
            for (int j_index = b.length() - 1; j_index >= 0; j_index--)
            {
                int ans = 0;
                if (a[i_index] == b[j_index])
                {
                    ans = 1 + nextRow[j_index + 1];
                }
                else
                {
                    ans = 0 + max(currRow[j_index + 1],
                                  nextRow[j_index]);
                }
                currRow[j_index] = ans;
            }
            // Shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int i = 0;
        int j = 0;
        // // Using Recursion
        // int ans =  solveUsingRecursion(text1, text2, i, j);

        // // Using Memoisation
        // vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));
        // int ans = solveUsingMem(text1, text2, i, j, dp);

        // // Using Tabulation
        // int ans = solveUsingTab(text1, text2);

        // // Space Optimisation

        // Column Wise Ans Nikal Rahe hai
        // int ans = solveUsingTabSO(text1, text2);

        // Row Wise Ans Nikal Rahe hai
        int ans = solveUsingTabSONoLoopChange(text1, text2);

        return ans;
    }
};

int main()
{
    Solution sol;

    // Input two strings
    string text1, text2;
    cout << "Enter the first string: ";
    cin >> text1;
    cout << "Enter the second string: ";
    cin >> text2;

    // Find and print the length of longest common subsequence
    int result = sol.longestCommonSubsequence(text1, text2);
    cout << "The length of the longest common subsequence is: " << result << endl;

    return 0;
}