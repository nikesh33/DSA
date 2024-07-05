#include <iostream>
#include <vector>
using namespace std;

                            // I/P   3, 1, -2, -5, 2, -4
                            // O/P   3, -2, 1, -5, 2, -4
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> result(size);
        int positiveIndex = 0;
        int negativeIndex = 1;

        for (int i = 0; i < size; i++)
        {
            if (nums[i] > 0)
            {
                result[positiveIndex] = nums[i];
                positiveIndex += 2;
            }
            else
            {
                result[negativeIndex] = nums[i];
                negativeIndex += 2;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4, -6, 8};
    // 3, -2, 1, -5, 2, -4
    int size = arr.size();
    Solution sol;
    vector<int> ans = sol.rearrangeArray(arr);

    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}