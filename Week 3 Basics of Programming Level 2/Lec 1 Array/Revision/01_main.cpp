#include <iostream>
using namespace std;

int main()
{
    // // array creation
    // int arr[101];
    // char ch[102];
    // bool flags[223];
    // short sh[1000];
    // cout << "Array created Successfully" << endl;

    // // my array is starting from which address? (&)
    // int a = 5;
    // cout << "Starting address of int a: " << &a << endl;
    // cout << "Starting address of int a: " << &a << endl;
    // cout << "Starting address of int a: " << &a << endl;

    // cout << "**************ARRAY********************" << endl;
    // int arr[100] = {10, 20};
    // cout << "Starting Address of array: " << &arr[0] << endl;
    // cout << "Starting Address of array: " << &arr[1] << endl;
    // cout << "Starting Address of array: " << &arr[2] << endl;
    // cout << "Starting Address of array: " << &arr[3] << endl;
    // cout << "Starting Address of array: " << &arr[4] << endl;

    // // dono case me same result hoga which means without (&) the arr will give same address kyuki dono starting address ko represent karte hai
    // cout << &arr << endl;
    // cout << arr << endl;

    // how to know size of??  (sizeof)
    int a = 5;
    int b = 50;
    int arr[10];
    cout << "Size of a: " << sizeof(a) << endl;
    cout << "Size of a: " << sizeof(b) << endl;

    // int = 4 arr= 10 int*arr = 40
    cout << "Size of arr: " << sizeof(arr) << endl;

    return 0;
}