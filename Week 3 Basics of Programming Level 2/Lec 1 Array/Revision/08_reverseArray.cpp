#include <iostream>
using namespace std;

//"Mind clicked" - function which are calling should be on top level if we want to call printArray it should be not below of that function it should be on above
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverseArray(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    // print
    printArray(arr, size);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    printArray(arr, size);
    cout << endl;
    reverseArray(arr, size);
}