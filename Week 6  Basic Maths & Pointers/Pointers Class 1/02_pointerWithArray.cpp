#include <iostream>
using namespace std;

int main()
{
    // int arr[5] = {10,20,30,40,50};
    // cout<<"arr : "<<arr<<endl;
    // cout<<"arr[0] : "<<arr[0]<<endl;
    // cout<<"&arr[0] : "<<&arr[0]<<endl;
    // cout<<"&arr : "<<&arr<<endl;

    // // ********IMPORTANT************* //
    // // in case of pointer
    // int a = 10;
    // int *ptr = &a;

    // ptr = ptr + 1;
    // cout << *ptr << endl;

    // // in case of array :
    // // arrays are not modifiable lvalues, meaning you cannot reassign an entire array or change its address directly. However, you can work with pointers to achieve similar functionality.
    // int arr1[5] = {1, 2, 3, 4, 5};
    // arr1 = arr1 + 1;

    // // Array pointer
    // int arr[5] = {10, 20, 30, 40, 50};

    // int *ptr = arr;
    // ptr = ptr + 1;
    // cout << *ptr << endl;
    // cout << &arr[0];

    // Practice
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;     // p is the pointer
    int *q = arr + 1; // q is the the pointer

    cout << arr << endl;
    cout << &arr << endl;
    cout << arr[0] << endl;
    cout << &arr[0] << endl;

    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl;

    cout << q << endl;
    cout << &q << endl;
    cout << *q << endl;

    cout << *p + 1 << endl;
    cout << *(p) + 2 << endl;
    cout << *(q) + 2 << endl;
    cout << *(q + 4) << endl;

    // size
    cout << "Size of arr : " << sizeof(arr) << endl; //(int = 4 byte ) 4*5 = 20

    // in case of pointer
    cout << "Size of Pointer : " << sizeof(p); // always 8 
}