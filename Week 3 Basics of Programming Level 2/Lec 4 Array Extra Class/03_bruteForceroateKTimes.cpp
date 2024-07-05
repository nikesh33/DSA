#include <iostream>
using namespace std;

void arrayRotatorbyKElement(int arr[], int size, int k)
{

    // Edge Cases
    // int size = nums.size();
    if (size == 0)
        return;
    k = k % size;

    int temp[k];
    // copying the last two element of array i.e {40,50}
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[size - k + i];
    }

    //  looping from index => end to k=2;
    for (int i = size - 1; i >= k; i--)
    {
        arr[i] = arr[i - k];
    }

    // Pasting the last two element in first two index i.e k=2 {50,60} from temp array
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

// function for printing the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 0;
    int k;
    cout << "Enter the Value of K: ";
    cin >> k;

    // before
    cout << "Printing Before the function " << endl;
    printArray(arr, size);
    arrayRotatorbyKElement(arr, size, k);
    cout << endl;
    // AFter
    cout << "Printing Before the function " << endl;
    printArray(arr, size);
}