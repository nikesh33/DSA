#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solveUsingRecursion(vector<int> &nums, int index)
    {
        // Base Case
        if (index >= nums.size())
        {
            return 0;
        }

        // Recursive Relation
        int include = nums[index] + solveUsingRecursion(nums, index + 2);
        int exclude = 0 + solveUsingRecursion(nums, index + 1);
        int ans = max(include, exclude);
        return ans;
    }

    int solveUsingMem(vector<int> &nums, int index, vector<int> &dp)
    {
        // Base Case
        if (index >= nums.size())
        {
            return 0;
        }

        // 3 ans exist
        if (dp[index] != -1)
        {
            return dp[index];
        }

        // Recursive Relation
        int include = nums[index] + solveUsingMem(nums, index + 2, dp);
        int exclude = 0 + solveUsingMem(nums, index + 1, dp);
        dp[index] = max(include, exclude);
        return dp[index];
    }

    int solveUsingTabulation(vector<int> &nums)
    {
        int n = nums.size(); 
        // 1 Craete DP ArrAY
        vector<int> dp(n, -1);

        // 2 bAse case analayse and fill dp array
        //  dp[index]? ->
        dp[n - 1] = nums[n - 1];

        // 3 fill remaining DP array
        for (int index = n - 2; index >= 0; index--)
        {
            int tempAns = 0;
            if (index + 2 < n)
            {
                tempAns = dp[index + 2];
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + dp[index + 1];
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }

    int solveUsingTabulationSpaceOptimised(vector<int> &nums)
    {
        int n = nums.size();
        // 1 Craete DP ArrAY
        // vector<int> dp(n, -1);

        // 2 bAse case analayse and fill dp array
        //  dp[index]? ->
        // dp[n - 1] = nums[n - 1];

        int prev = nums[n - 1];
        int next = 0;
        int curr = 0;
        // 3 fill remaining DP array
        for (int index = n - 2; index >= 0; index--)
        {
            int tempAns = 0;
            if (index + 2 < n)
            {
                tempAns = next;
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + prev;
            curr = max(include, exclude);

            //    bhul jata hu
            next = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int> &nums)
    {
        int index = 0;
        // int ans = solveUsingRecursion(nums,index);
        // return ans;

        // // 1 Create a DP array ->1D Array
        // int n = nums.size();
        // vector<int>dp(n+1,-1);
        // int ans = solveUsingMem(nums,index,dp);
        // return ans;

        // 2 -> Tabulation
        int ans = solveUsingTabulationSpaceOptimised(nums);
        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    Solution sol;
    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}
