#include <iostream>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return 1;
        }

        int ans = climbStairs(n - 1) + climbStairs(n - 2);
        return ans;
    }
};

int main()
{
    Solution sol;

    cout<<"Total Number of ways to reach n: "<<sol.climbStairs(3);
}