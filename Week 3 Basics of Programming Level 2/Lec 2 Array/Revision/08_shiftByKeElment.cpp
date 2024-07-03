#include <iostream>
using namespace std;

void shiftByKElement(int arr[], int n)
{
    int temp = arr[n-1];

    for (int i = 0; i < n; i++)
    {
        /* code */
    }
    
}

int main()
{
                 // 50  40 10 20 30
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;

    shiftByKElement(arr, n);

    // print
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}