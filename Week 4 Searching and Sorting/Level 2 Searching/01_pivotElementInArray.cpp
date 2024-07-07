#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getPivot(vector<int> &arr, int size)
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
};

int main()
{
    // Create an instance of the Solution class
    Solution sol;

    // Example rotated sorted array and target
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    //  int arr[] = {12, 14, 16, 2, 4, 6, 8, 10};
    int size = arr.size();

    cout << sol.getPivot(arr, size);
}
