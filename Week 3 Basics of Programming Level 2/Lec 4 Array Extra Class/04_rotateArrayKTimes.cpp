#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Modulus Method
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n);
        // ans array bana liya n size ka 
        for (int index = 0; index < n; index++)
        {
            // 0+2%6 = 2  
            // 1+2%6 = 3
            // 2+2%6 = 4
            // 3+2%6 = 5
            // 4+2%6 = 0
            // 5+2%6 = 1
            int newIndex = (index + k) % n;
            ans[newIndex] = nums[index];
        }
        nums = ans;
    }
};

int main()
{

    Solution rotatorbyK;
    vector<int> nums = {10, 20, 30, 40, 50, 60};
    int k = 2;
    rotatorbyK.rotate(nums, k);

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}