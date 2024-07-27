#include <iostream>
using namespace std;

// ***********Printing Array Using Recursion*************//

void printArray(int arr[], int size, int index)
{
    if (index >= size)
    {
        return;
    }

    // processing
    cout << arr[index] << " ";

    // recursive call
    printArray(arr, size, index + 1);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int index = 0;
    printArray(arr, size, index);
}