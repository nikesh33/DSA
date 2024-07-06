#include <iostream>
using namespace std;

int lastFirstOccurence(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        // found
        if (arr[mid] == target)
        {
            // go right and check if target is in right side
            // store mid as new ans (Index)
            ans = mid;
            start = mid + 1;
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
        mid = start + (end - start) / 2;
    }
    return ans;
}
 
int main()
{
    int arr[] = {10, 30, 30, 30, 80, 90};
    int size = 6;
    int target = 30;

    int ansIndex = lastFirstOccurence(arr, size, target);

    if (ansIndex == -1)
    {
        cout << "Element Not Found ";
    }
    else
    {
        cout << "First Occurence of element found at Index: " << ansIndex;
    }
}