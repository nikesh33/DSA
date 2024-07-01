#include <iostream>
using namespace std;

// int pairElement(int arr[], int size)
// {
//     int left = 0;
//     int right = 0;

//     while (left<=right)
//     {
//         cout<<arr[left],arr[right];

//     }

// }

int main()
{
    int arr[3] = {10, 20, 30};
    int size = 3;

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            cout << arr[i] << ", " << arr[j] << endl;
        }
    }
}