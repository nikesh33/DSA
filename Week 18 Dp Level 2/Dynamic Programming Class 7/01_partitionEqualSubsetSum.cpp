#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Using Recursion
    bool solveUsingRecursion(vector<int> &arr, int index, int currSum, int target)
    {
        if (index >= arr.size())
        {
            return 0;
        }

        if (currSum > target)
        {
            return 0;
        }
        if (currSum == target)
        {
            return true;
        }

        // recursion
        bool include =
            solveUsingRecursion(arr, index + 1, currSum + arr[index], target);
        bool exclude = solveUsingRecursion(arr, index + 1, currSum, target);

        return include || exclude;
    }

    // Using Memoisation
    bool solveUsingMem(vector<int> &arr, int index, int currSum, int target, vector<vector<int>> &dp)
    {
        if (index >= arr.size())
        {
            return 0;
        }

        if (currSum > target)
        {
            return 0;
        }
        if (currSum == target)
        {
            return true;
        }

        if (dp[index][currSum] != -1)
        {
            return dp[index][currSum];
        }

        // recursion
        bool include =
            solveUsingMem(arr, index + 1, currSum + arr[index], target, dp);
        bool exclude = solveUsingMem(arr, index + 1, currSum, target, dp);

        return dp[index][currSum] = (include || exclude);
    }

    // Using Tabulation
    bool solveUsingTab(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 2, vector<int>(target + 1, 0));

        for (int row = 0; row <= arr.size(); row++)
        {
            dp[row][target] = 1;
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int s = target; s >= 0; s--)
            {
                // recursion
                bool include = 0;
                if (s + arr[ind] <= target)
                {
                    include = dp[ind + 1][s + arr[ind]];
                }

                bool exclude = dp[ind + 1][s];
                dp[ind][s] = (include || exclude);
            }
        }
        return dp[0][0];
    }

    // Space Optimisation
    bool solveUsingTabSO(vector<int> &arr, int target)
    {
        int n = arr.size();
        // vector<vector<int>> dp(n + 2, vector<int>(target + 1, 0));
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        curr[target] = 1;
        next[target] = 1;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int s = target; s >= 0; s--)
            {
                // recursion
                bool include = 0;
                if (s + arr[ind] <= target)
                {
                    include = next[s + arr[ind]];
                }

                bool exclude = next[s];
                curr[s] = (include || exclude);
            }
            // shifting
            next = curr;
        }
        return next[0];
    }

    bool canPartition(vector<int> &nums)
    {
        int index = 0;
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }
        if (totalSum & 1)
        {
            // odd case
            return false;
        }

        // Using Recursion
        int target = totalSum / 2;
        int currSum = 0;
        // bool ans = solveUsingRecursion(nums, index, currSum, target);

        // Using Memoisation
        // int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // bool ans = solveUsingMem(nums, index, currSum, target, dp);

        // // Using Tabulation
        // bool ans = solveUsingTab(nums, target);

        // Space Optimisation
        bool ans = solveUsingTabSO(nums, target);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 5, 11, 5}; // Example input array
    bool result = sol.canPartition(nums);

    if (result)
    {
        cout << "Can partition the array into two subsets with equal sum." << endl;
    }
    else
    {
        cout << "Cannot partition the array into two subsets with equal sum." << endl;
    }

    return 0;
}
