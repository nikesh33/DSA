#include <iostream>
using namespace std;

void extremeArray(int arr[], int size)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        // 1 he bar print hoga nhi to 2 bar aa jata tha
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
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    // 10 70 20  60 30 50 40
    int size = 7;

    extremeArray(arr, size);
}