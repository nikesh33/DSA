#include <iostream>
using namespace std;

void solve(int *arr, int size)
{
    // cout << "Inside size: " << sizeof(arr) << endl;
    // cout << "Inside solve => arr: " << arr << endl;
    // cout << "Inside solve => &arr: " << &arr << endl;

    *arr = *arr + 1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 67, 10, 20, 39, 55}; // 4*10
    cout << "Inside main => arr: " << arr << endl;
    cout << "Inside main => &arr: " << &arr << endl;
    cout << "Inside main: " << sizeof(arr) << endl;
    solve(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}