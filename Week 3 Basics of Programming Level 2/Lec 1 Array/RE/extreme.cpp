#include <iostream>
using namespace std;

void extremePrint(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        if (left == right)
        {
            cout << arr[left] << " ";
        }
        else
        {
            cout << arr[left] << " ";
            cout << arr[right] << " ";
        }

        left++;
        right--;
    }

    // // print
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }
}

int main()
{
    // Array => 10 20 30 40 50 60
    // Output => 10 60 20 50 30 40
    int arr[6] = {10, 20, 30, 40, 50, 60};
    int size = 6;

    extremePrint(arr, size);
}