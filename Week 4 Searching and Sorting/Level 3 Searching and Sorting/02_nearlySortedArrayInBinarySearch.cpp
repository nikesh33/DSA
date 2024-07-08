#include <iostream>
using namespace std;

int getNearlySearch(int arr[], int size, int target)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (mid - 1 >= 0 && arr[mid - 1] == target)
        {
            return mid - 1;
        }
        if (arr[mid] == target)
        {
            return mid;
        }

        if (mid + 1 < size && arr[mid + 1] == target)
        {
            return mid + 1;
        }
        if (target > arr[mid])
        {
            s = mid + 2;
        }
        else
        {
            e = mid - 2;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    int arr[] = {20, 10, 30, 50, 40, 70, 60};
    int size = 7;
    int target = 50;

    int index = getNearlySearch(arr, size, target);

    if (index == -1)
    {
        cout << "Element Not Found";
    }

    else
    {
        cout << "Element Found " << index;
    }
}