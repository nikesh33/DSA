#include <iostream>
using namespace std;

int findFirstOccurence(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    int ans = -1;

    while (start <= end)
    {
        // found
        if (arr[mid] == target)
        {
            // go left and check if target is in left side
            // store mid as new ans (Index)
            end = mid - 1;
            ans = mid;
        }
        else if (target > arr[mid])
        {
            // go right
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            // go left
            end = mid - 1;
        }
        // update mid
        mid = (start + end) / 2;
    }
    return ans;
}

int main()
{
    int arr[] = {10, 20, 30, 30, 50, 30};
    int size = 6;
    int target = 90;

    int ans = findFirstOccurence(arr, size, target);

    if (ans == -1)
    {
        cout << "Element Not Found ";
    }
    else
    {
        cout << "First Occurence of element found at Index: " << ans;
    }
}