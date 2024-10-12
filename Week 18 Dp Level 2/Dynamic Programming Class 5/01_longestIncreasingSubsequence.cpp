#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solveUsingRecursion(vector<int> &nums, int curr, int prev)
    {

        // Base Case
        if (curr >= nums.size())
        {
            return 0;
        }
        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev])
        {
            include = 1 + solveUsingRecursion(nums, curr + 1, curr);
        }

        int exclude = 0 + solveUsingRecursion(nums, curr + 1, prev);

        int ans = max(include, exclude);
        return ans;
    }

    // Using Memoisation
    int solveUsingMem(vector<int> &nums, int curr, int prev,
                      vector<vector<int>> &dp)
    {
        // Base Case
        if (curr >= nums.size())
        {
            return 0;
        }

        // prev+1 we are doing index shifting because prev = -1 that is not an
        // valiod col
        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1];
        }

        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev])
        {
            include = 1 + solveUsingMem(nums, curr + 1, curr, dp);
        }

        int exclude = 0 + solveUsingMem(nums, curr + 1, prev, dp);

        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    }

    // Using Tabulation
    int solveUsingTabulation(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr_index = n - 1; curr_index >= 0; curr_index--)
        {
            for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--)
            {
                int include = 0;
                if (prev_index == -1 || nums[curr_index] > nums[prev_index])
                {
                    include = 1 + dp[curr_index + 1][curr_index + 1]; // index shifting
                }

                int exclude = 0 + dp[curr_index + 1][prev_index + 1]; // index shifting
                dp[curr_index][prev_index + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    // Space Optimisation
    int solveUsingTabulationSO(vector<int> &nums)
    {
        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr_index = n - 1; curr_index >= 0; curr_index--)
        {
            for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--)
            {
                int include = 0;
                if (prev_index == -1 || nums[curr_index] > nums[prev_index])
                {
                    include = 1 + nextRow[curr_index + 1]; // index shifting
                }

                int exclude = 0 + nextRow[prev_index + 1]; // index shifting
                currRow[prev_index + 1] = max(include, exclude);
            }
            // Shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    // Using Binary Search to solve
    //****BINARY SEARCH APPROACH****//
    int solveUsingBS(vector<int> &nums)
    {
        // koi array chahiye hoga jisme main ans built karunga
        vector<int> ans;
        // Initial State => 0th index pe jo bhi hai mujhe include karna he padega
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                // just bada number exist karta hai
                // index of just bada number
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                //    replace
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int> &nums)
    {
        // Using Recursion
        int prev = -1;
        int curr = 0;
        // int ans = solveUsingRecursion(nums, curr, prev);

        // // Using Memoisation
        // // curr and prev both are changing so its a 2D ARRAY
        // int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // int ans = solveUsingMem(nums, curr, prev, dp);

        // // Using Tabulation
        // int ans = solveUsingTabulation(nums);

        // // Space Optimisation
        // int ans = solveUsingTabulationSO(nums);

        //****BINARY SEARCH APPROACH****//
        int ans = solveUsingBS(nums);

        return ans;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Calling the lengthOfLIS function
    int result = sol.lengthOfLIS(nums);

    // Output the result
    cout << "The length of the longest increasing subsequence is: " << result << endl;

    return 0;
}
