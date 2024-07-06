#include <iostream>
using namespace std;

int findMissingElement(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        // int diff = arr[mid] - mid;

        if (arr[mid] - mid == 1)
        {
            start = mid + 1;
        }
        else
        {
            ans = mid;
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    // this for the last case when the missing element is at the last position becuase the ans will come as 0
    if (ans + 1 == 0)
    {
        return n + 1;
    }

    return ans + 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 9};
    int size = 8;

    cout << findMissingElement(arr, size);
    // jab tak missing element nhi aya hai tab tak +1 wala pattern chalega
}