#include <iostream>
using namespace std;

int find(int arr[], int size, int index, int target)
{
    // base case
    if (index >= size)
    {
        return -1;
    }

    // to find index of number
    // processing
    // if (arr[index] == target)
    // {
    //     return index;
    // }

    // processing
    // for  all occurences print index of respectively
    if (arr[index] == target)
    {
        cout << index << " ";
    }

    // rc
    return find(arr, size, index + 1, target);
}

int main()
{
    int arr[] = {10, 20, 10, 40, 10};
    int size = 5;
    int index = 0;
    int target;
    cout << "Enter Target: ";
    cin >> target;
    cout << "In All of these Indexes we found target: ";
    find(arr, size, index, target);

    // just for understanding
    // int final = find(arr, size, index, target);
    // if (final == -1)
    // {
    //     cout << "Target Not Found " << final;
    // }
    // else
    // {

    //     cout << "Target Found At Index: " << final;
    // }
}