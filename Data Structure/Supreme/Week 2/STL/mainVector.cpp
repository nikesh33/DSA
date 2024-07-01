#include <iostream>
#include <vector>
using namespace std;

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    // // 0 way: Static Memory allocation array
    // int arr[5]={10,20,30,40,50};
    // cout<<"Static Memory Allocation: ";
    // print(arr,5);

    // // 1 way: Dynamic Memory allocation array
    // int size;
    // cin >> size;
    // int *arr = new int[size]; // each element will be 0 or garbage by-default
    // // taking n array elements in array and inserting in array
    // for (int i = 0; i < size; ++i)
    // {
    //     int data;
    //     cin >> data;
    //     arr[i] = data;
    // }
    // cout << "Dynamic Memory Allocation Array: ";
    // print(arr, size);
    // // in this method if we are giving array of size 5 and if we want add element after 5 it will throw array (malloc) due to this STL comes in Picture
}