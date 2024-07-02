#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

// minimum number in given array
int findMinInArray(int arr[], int size)
{
    int minAns = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < minAns)
        {
            minAns = arr[i];
        }
    }
    return minAns;
}
// maximum number in given array
int findMaximumInArray(int arr[], int size)
{
    int maxAns = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxAns)
        {
            maxAns = arr[i];
        }
    }
    return maxAns;
}

// main  function
int main()
{
    /*
    //way 1
    int arr[6] = {10, 21, 33, 90, 22, 121};
    int size = 6;

    int minAns = INT_MAX;
    int maxAns = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < minAns)
        {
            minAns = arr[i];
        }
        if (arr[i] > maxAns)
        {
            maxAns = arr[i];
        }
    }
    cout << "Minimum Ans: " << minAns << endl;
    cout << "Maximum Ans: " << maxAns;
    */

    int arr[12] = {29, 34, 89, 12, 95, 33, 21, 43, 56, 33, 404, 2};
    int size = 12;

    int ansMin = findMinInArray(arr, size);
    int ansMax = findMaximumInArray(arr, size);
    cout << "Minimum Value in given array is: " << ansMin << endl;
    cout << "Maximum Value in given array is: " << ansMax;
}