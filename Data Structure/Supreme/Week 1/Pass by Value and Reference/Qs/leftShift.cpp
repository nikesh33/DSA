#include <iostream>
using namespace std;

void shiftRight(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n-1] = temp;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;

    shiftRight(arr, n);

    // print
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}