#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        // this will give a sum of all in array except missing one
        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
        }
        // this will give a total sum
        int totalSum = ((n) * (n + 1)) / 2;
        int ans = totalSum - sum;
        return ans;
    }
};

int main()
{
    vector<int> arr = {0, 1, 7, 3, 4, 5, 6, 8};
    Solution sol;
    int ans = sol.missingNumber(arr);
    cout << ans;
}