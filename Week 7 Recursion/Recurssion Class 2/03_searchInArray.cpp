#include <iostream>
using namespace std;

bool searchArray(int arr[], int size, int index, int target)
{
    // base case
    if (index >= size)
    {
        return false;
    }

    if (arr[index] == target)
    {
        return true;
    }

    // recursive call
    bool aageKaAns = searchArray(arr, size, index + 1, target);
    return aageKaAns;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int index = 0;
    int target = 20;

    cout << "Found(1) or Not(0): " << searchArray(arr, size, index, target);
}