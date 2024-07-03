#include <iostream>
using namespace std;

void shiftArrayByOne(int arr[], int n)
{
    int temp = arr[0]; // 0 wale element ko save karlo

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i + 1]; // arr[20,30,40,50,10]
    }

    arr[n - 1] = temp;
}

int main()
{
     // 20 30 40 50 60 10
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = 6;

    shiftArrayByOne(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}