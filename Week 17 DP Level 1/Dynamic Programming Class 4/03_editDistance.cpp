#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Using Recursion
    int solveUsingRecursion(string &a, string &b, int i, int j)
    {
        // base case
        if (i == a.length())
        {
            return b.length() - j;
        }

        if (j == b.length())
        {
            return a.length() - i;
        }

        int ans = 0;
        if (a[i] == b[j])
        {
            ans = solveUsingRecursion(a, b, i + 1, j + 1);
        }
        else
        {
            int replace = 1 + solveUsingRecursion(a, b, i + 1, j + 1);
            int insert = 1 + solveUsingRecursion(a, b, i, j + 1);
            int remove = 1 + solveUsingRecursion(a, b, i + 1, j);
            ans = min(insert, min(remove, replace));
        }
        return ans;
    }

    // Using Memoisation
    int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i == a.length())
        {
            return b.length() - j;
        }

        if (j == b.length())
        {
            return a.length() - i;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;
        if (a[i] == b[j])
        {
            ans = 0 + solveUsingMem(a, b, i + 1, j + 1, dp);
        }
        else
        {
            int replace = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
            int insert = 1 + solveUsingMem(a, b, i, j + 1, dp);
            int remove = 1 + solveUsingMem(a, b, i + 1, j, dp);
            ans = min(insert, min(remove, replace));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int minDistance(string word1, string word2)
    {
        int i = 0;
        int j = 0;
        // // Using Recursion
        // int ans = solveUsingRecursion(word1, word2, i, j);

        // // Using Memoisation
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        int ans = solveUsingMem(word1, word2, i, j, dp);
        return ans;
    }
};

int main()
{
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";

    int result = sol.minDistance(word1, word2);
    cout << "Minimum number of operations required: " << result << endl;

    return 0;
}
