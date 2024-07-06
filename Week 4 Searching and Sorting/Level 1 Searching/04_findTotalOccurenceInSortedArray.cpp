#include <iostream>
using namespace std;

// ********First Occurence Function*************//
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
            ans = mid;
            end = mid - 1;
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

// ********Last Occurence Function*************//
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

// ******************Total Occurence Function***************************//

int totalOccurence(int arr[], int size, int target)
{
    int firstOccurence = findFirstOccurence(arr, size, target);
    int lastOccurence = lastFirstOccurence(arr, size, target);

    int totalOccurenceAns = lastOccurence - firstOccurence + 1;
    return totalOccurenceAns;
}

int main()
{
    int arr[] = {10, 30, 30, 30, 40, 50};
    int size = 6;
    int target = 30;

    int totalAns = totalOccurence(arr, size, target);
    cout << "Total Occurence in Sorted Array is: " << totalAns;
}