// #include <iostream>
// using namespace std;

// int binarySearch(int arr[], int start, int end, int target)
// {
//     // base case
//     if (start > end)
//     {
//         return -1;
//     }

//     // processing => 1 case khud solve karo
//     int mid = start + (end - start) / 2;
//     if (arr[mid] == target)
//     {
//         return mid;
//     }

//     // baaki ka recursion sambhal lega
//     if (arr[mid] < target)
//     {
//         // right me jao

//         return binarySearch(arr, mid + 1, end, target);
//     }
//     else
//     {
//         return binarySearch(arr, start, mid - 1, target);
//     }
// }

// int main()
// {
//     int arr[] = {10, 20, 30, 40, 60};
//     int size = 5;
//     int start = 0;
//     int end = size - 1;
//     int target = 90;

//     int finalAns = binarySearch(arr, start, end, target);

//     if (finalAns != -1)
//     {
//         cout << "Target found at: " << finalAns;
//     }
//     else
//     {
//         cout << "Target Not Found: " << finalAns << endl;
//     }
// }

// *****Practice

#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target)
{
    // base case
    if (start > end)
    {
        return -1;
    }

    // 1 case
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }

    // baki ka case
    if (arr[mid] < target)
    {
        // right me jao
        return binarySearch(arr, mid + 1, end, target);
    }
    else
    {
        // left me jao
        return binarySearch(arr, start, mid - 1, target);
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int start = 0;
    int end = size - 1;
    int target = 30;

    int ans = binarySearch(arr, start, end, target);
    if (ans != -1)
    {
        cout << "Target Found At Index: " << ans;
    }
    else
    {
        cout << "Target Not Found: " << ans;
    }

    return 0;
}