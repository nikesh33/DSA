#include <iostream>
using namespace std;

// Recursively
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

void buildHeap(int arr[], int n)
{
    for (int index = n / 2; index > 0; index--)
    {
        heapify(arr, n, index);
    }
}

int main()
{

    int arr[] = {-1, 4, 10, 3, 5, 1}; // Example array with 1-based indexing (-1 is a placeholder)
    int n = 5;                        // Size of the array (excluding placeholder)

    cout << "Original array: ";
    printArray(arr, n);

    // Build the heap from the array
    buildHeap(arr, n);

    cout << "Array after building the heap: ";
    printArray(arr, n);

    return 0;
}