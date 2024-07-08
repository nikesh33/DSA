#include <iostream>
using namespace std;

int oddOccuringElement(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        //   for single element s==e
        if (s == e)
        {
            return s;
        }

        // odd
        if (mid & 1)
        {
            if (mid - 1 >= 0 && arr[mid] == arr[mid - 1])
            {
                // go right
                s = mid + 1;
            }
            else
            {
                // go left
                e = mid - 1;
            }
        }

        else
        {
            // even
            if (mid + 1 <= n && arr[mid] == arr[mid + 1])
            {
                // go right
                s = mid + 2;
            }
            else
            {
                e = mid;
            }
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 1, 5, 5, 2, 2, 3, 3, 8, 4, 4};
    int n = 11;

    int ans = oddOccuringElement(arr, n);
    cout << "Odd Occuring In an Array is: " << arr[ans];
}