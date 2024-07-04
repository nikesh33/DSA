#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int index = 0;
        int left = 0;
        int right = n - 1;

        while (index <= right)
        {
            if (nums[index] == 0)
            {
                // if zero hai swap karo index ko left ke sath ,left ko aage badhao,index ko bhi aage le jao
                swap(nums[index], nums[left]);
                left++;
                index++;
            }
            else if (nums[index] == 2)
            {
                swap(nums[index], nums[right]);
                right--;
                // index++; =>  ye nhi karna hai, yaha galti hogi
            }
            else
            {
                // agar 1 hai to ignore karo aage badho
                index++;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}