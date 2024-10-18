#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solveUsingRecursion(int n, int k, int target)
    {

        if (target == 0 && n == 0)
        {
            return 1;
        }
        if (target != 0 && n == 0)
        {
            return 0;
        }
        if (target == 0 && n != 0)
        {
            return 0;
        }

        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans += solveUsingRecursion(n - 1, k, target - 1);
        }
        return ans;
    }
    int numRollsToTarget(int n, int k, int target)
    {

        int ans = solveUsingRecursion(n, k, target);
        return ans;
    }
};

int main()
{
    Solution solution;

    int n, k, target;
    cout << "Enter the number of dice (n): ";
    cin >> n;
    cout << "Enter the number of faces on each die (k): ";
    cin >> k;
    cout << "Enter the target sum (target): ";
    cin >> target;

    int result = solution.numRollsToTarget(n, k, target);
    cout << "Number of ways to roll " << n << " dice with " << k
         << " faces to get the target sum " << target << " is: " << result << endl;

    return 0;
}