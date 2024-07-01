// Negative elemnet on left side and positive element on right in sorted array

#include <iostream>
using namespace std;

void shiftNegativeToOneSide(int arr[], int n)
{
    int j = 0;

    for (int index = 0; index < n; index++)
    {
        if (arr[index] < 0)
        {
            swap(arr[index],arr[j]);
            j++;
        }
    }
}

int main()
{
    int arr[] = {23, -7, 12, -10, -11, 0, 60};
    int n = 7;

    shiftNegativeToOneSide(arr, n);

    // for printing an array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}