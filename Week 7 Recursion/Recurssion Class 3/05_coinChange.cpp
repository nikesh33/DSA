#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &coins, int amount)
    {
        // base case
        if (amount == 0)
        {
            return 0;
        }

        int mini = INT_MAX;
        int ans = INT_MAX; // amount ko jo ans ayega
        for (int i = 0; i < coins.size(); i++)
        {
            int coin = coins[i];

            // current coin ko sir tabhi use karenge
            // jab uski value <= amount hogi
            if (coin <= amount)
            {
                int recAns = solve(coins, amount - coin);
                if (recAns != INT_MAX)
                    ans = 1 + recAns;
            }
            mini = min(mini, ans);
        }
        return mini;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int ans = solve(coins, amount);

        if (ans == INT_MAX)

            return -1;
        else
            return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = sol.coinChange(coins, amount);
    cout << "Minimum coins needed: " << result << endl;
    return 0;
}