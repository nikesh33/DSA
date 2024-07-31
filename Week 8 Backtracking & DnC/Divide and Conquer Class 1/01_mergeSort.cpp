#include <iostream>
using namespace std;

void merge(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;

    int lenLeft = mid - start + 1;
    int lenRight = end - mid;

    // create left and right array
    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    // copy values from original array to left array
    int k = start;
    // k => starting index of left array values in original array
    for (int i = 0; i < lenLeft; i++)
    {
        left[i] = arr[k];
        k++;
    }

    // copy values from original array to right array
    k = mid + 1;
    for (int i = 0; i < lenRight; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // actual merge logic here
    // left array is already sorted
    // right array is already sorted
    int leftIndex = 0;
    int rightIndex = 0;
    // yaha pe galti hogi
    int mainArrayIndex = start;

    while (leftIndex < lenLeft && rightIndex < lenRight)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }

        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // 2 more cases
    // 1 case => left array exhaust but right array me element abhi bhi bache hai
    while (rightIndex < lenRight)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    // 2nd case => right array exhaust but left array me element abhi bhi bacha hai
    while (leftIndex < lenLeft)
    {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    // 1 more step pending
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int start, int end)
{
    // base case
    if (start > end)
    {
        // invalid case
        return;
    }
    if (start == end)
    {
        // single element
        return;
    }

    // break in half
    int mid = start + (end - start) / 2;
    // start => mid => left
    // mid+1 => end => right

    // recursion call
    // left and right array ko sort karao
    // recursive call for left array
    mergeSort(arr, start, mid);
    // recursive call for right array
    mergeSort(arr, mid + 1, end);

    //  merge 2 sorted  arrays
    merge(arr, start, end);
}

int main()
{
    int arr[] = {2, 1, 9, 7, 4, 6};
    int size = 6;
    int start = 0;
    int end = size - 1;

    // printing before
    cout << "Before merge Sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, start, end);

    cout << "After merge Sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}