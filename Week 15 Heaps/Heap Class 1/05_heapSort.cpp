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

void heapSort(int arr[], int n)
{
    while (n != 1)
    {
        // index one wale element ko swap kardo end ke sath
        swap(arr[1], arr[n]); // n-1 nahi lagana hota hai
        n--;
        heapify(arr, n, 1);
    }
}

int main()
{

    int arr[] = {-1, 5, 10, 15, 20, 25, 12};
    int n = 6;
    buildHeap(arr, 6);

    cout << "Printing Original Heap: " << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    heapSort(arr, n);
    cout << "Printing Heap Sort: " << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}