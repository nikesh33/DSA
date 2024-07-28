#include <iostream>
#include <vector>
using namespace std;

void doubleTruble(int arr[], int size, int index)
{
    // base
    if (index >= size)
    {
        return;
    }

    // process
    arr[index] = arr[index] * 2;

    // rc
    doubleTruble(arr, size, index + 1);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int index = 0;
    vector<int> ans;
    doubleTruble(arr, size, index);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}