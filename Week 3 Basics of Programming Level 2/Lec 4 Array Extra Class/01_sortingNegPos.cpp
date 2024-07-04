#include <iostream>
using namespace std;

void shiftNegativeOneSide(int arr[], int n)
{
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

void print(int arr[], int n)
{
    // o(n) time complexity
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {23, -7, 0, -10, -11, 40, 60};
    int n = 7;
    cout << "Before: ";
    print(arr, n);
    cout << endl;
    shiftNegativeOneSide(arr, n);
    cout << "After: ";
    print(arr, n);
}