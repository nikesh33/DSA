#include <vector>
using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> &arr, int start, int end, int target)
    {
        int mid = start + (end - start) / 2;

        while (start <= end)
        {
            if (arr[mid] == target)
            {
                return mid;
            }
            if (target > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return -1;
    }

    int getPivotElement(vector<int> &arr, int size)
    {
        int start = 0;
        int end = size - 1;
        int mid = start + (end - start) / 2;

        while (start <= end)
        {
            // corber case
            if (start == end)
            {
                // single element
                return start;
            }
            // if we are on 16 as mid or 2 as mid
            // mid is on 16 : index 2
            // mid+1 is on 2 : index 3
            // mid>mid+1 then return mid because its greater 16>2
            if (mid + 1 < size && arr[mid] > arr[mid + 1])
            { // Note: Range se bahar ja raha tha, yaha condition lagaana bhul gye the (mid+1>size)
                return mid;
            }

            // if we are on 16 as mid or 2 as mid
            // mid is on 2 : index 3
            // mid-1 is 16 : index 2
            // mid-1>mid then return mid-1 because its greater 16>2
            else if (mid - 1 >= 0 && arr[mid - 1] > arr[mid])
            { // Note: Range se bahar ja raha tha,yaha condition lagaana bhul gye the (mid-1>=0)
                return mid - 1;
            }

            // left
            // agar mid start se jyada hai to ans left me hoga left me jao
            else if (arr[start] > arr[mid])
            {
                end = mid - 1;
            }
            // right
            // agar mid se kam hai to left me ans hai
            else
            {
                start = mid + 1;
            }
            // update the mid element
            mid = start + (end - start) / 2;
        }

        // agar nhi hai present to return kar diya -1
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int size = nums.size();
        int pivotIndex = getPivotElement(nums, size);
        int ans = -1;

        // If pivot is found, there are two sorted arrays
        if (pivotIndex != -1)
        {
            // If target is in the first sorted array
            if (target >= nums[0] && target <= nums[pivotIndex])
            {
                ans = binarySearch(nums, 0, pivotIndex, target);
            }
            else
            { // If target is in the second sorted array
                ans = binarySearch(nums, pivotIndex + 1, size - 1, target);
            }
        }
        else
        { // If no pivot is found, it means the array is not rotated
            ans = binarySearch(nums, 0, size - 1, target);
        }

        return ans;
    }
};


#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Example rotated sorted array and target
    vector<int> nums = {15, 18, 2, 3, 6, 12};
    int target = 18;

    // Call the search function
    int result = solution.search(nums, target);

    // Print the result
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
