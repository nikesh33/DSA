#include <iostream>
#include <vector>
using namespace std;

// peak Index in array
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s < e)
        {
            if (arr[mid] < arr[mid + 1])
            {
                // A wali line me hu
                // peak element right me exist karti hai
                s = mid + 1;
            }
            else
            {
                // ya to main B line par hu
                // ya toh main Peak Element par hu
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        // koi bhi return kardo dono index single element pe hai same element pe h
        return s;
    }
};

int main()
{
    vector<int> arr = {10, 20, 50, 60, 30};
    Solution sol;
    cout << "Peak Index In a Mountain Array: " << sol.peakIndexInMountainArray(arr);
}