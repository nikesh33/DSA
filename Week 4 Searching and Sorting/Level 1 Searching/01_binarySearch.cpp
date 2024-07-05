#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{

    int start = 0;
    int end = size - 1;

    int mid = (start + end) / 2;

    while (start <= end)
    {

        // found
        if (arr[mid] == target)
        {
            // return index of the found element
            return mid;
        }
        else if (target > arr[mid])
        {
            // right me jao
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            // left me jao
            end = mid - 1;
        }
        // Note:  mid update
        mid = (start + end) / 2;
    }
    // agar yaha tak pauche ho
    // iska matlab element nahi mila tumhe
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    // 0 , 1, 2,  3,  4,   5,  6,  7,   8,
    int target = 90;

    int n = 9;

    int ansIndex = binarySearch(arr, n, target);

    if (ansIndex == -1)
    {
        cout << "Element not found " << endl;
    }
    else
    {
        cout << "Element found at Index: " << ansIndex << endl;
    }
}