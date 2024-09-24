#include <iostream>
using namespace std;

void heapify(int *arr, int n, int index)
{
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    // Initially starting ke index ko largestKaIndex Bol rahe hai
    int largestKaIndex = index;

    // Teeno me se max laao
    if (leftIndex <= n && arr[leftIndex] > arr[largestKaIndex])
    {
        largestKaIndex = leftIndex;
    }
    if (rightIndex <= n && arr[rightIndex] > arr[largestKaIndex])
    {
        largestKaIndex = rightIndex;
    }
    // after these 2 condition largestKaIndex will be pointing towards largest element among 3
    if (index != largestKaIndex)
    {
        swap(arr[index], arr[largestKaIndex]);
        // ab recursion sambhal lega
        index = largestKaIndex;
        heapify(arr, n, index);
    }
}

void printArray(int *arr, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[] = {45, 50, 60, 40, 30, 20};
    int n = 6;

    cout << "Original array: ";
    printArray(arr, n);

    heapify(arr, n, 1);
    cout << "Array after applying heapify: ";
    printArray(arr, n);

    return 0;
}