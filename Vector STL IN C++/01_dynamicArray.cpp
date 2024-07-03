// STL
// 1 => Standard Template Library provides collection of template classes and functions that offer common data structure and algorithms to make programming more efficient and convenient
// 2 => A Vector in C++ is dynamic array that can grow or shrink in size making it veratile and efficient data stucture for storing and manipulating sequence of elemnets
// VECTOR(Dynamic) => ARRAY

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    //  // static memory allocation of array
    // int arr[5]={10};
    // printArray(arr, 5);
    // Making it dynamic as we are taking size from user and making it from given user  size
    int n;
    cout << "Enter the Size of array you want to create: ";
    cin >> n;

    //  Normal dynamic memory allocation
    //  In this there is issue suppose if we say 5 size of array and push 5 item then if we want to put more element it will (say: Malloc(): corrupted top size)  its now a good thing because we have said 5 size and we are pushing more than 5 size

    int *arr = new int[n];
    // taking input in array
    cout << "Enter the Data: ";

    for (int i = 0; i < n; ++i)
    {
        int data;
        cin >> data;
        arr[i] = data;
    }

    for (int i = 0; i < 10; ++i)
    {
        arr[n + i] = 10;
    }

    printArray(arr, n);
}


// malloc 
