#include <iostream>
using namespace std;

int main()
{
    // int a = 10;
    // int ab[20];
    // cout << "Address of a " << &a;
    // cout << endl;
    // cout << "Address of arr " << &a;

    // int n = 15;
    // int arr[10] = {10,20,30,20,40,50,70};

    // for (int i = 0; i < n; i++)
    // {
    //     /* code */
    //     cout<<arr[i]<<" ";
    // }

    // int arr[5];
    // int n = 5;

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<"Enter the element of an array at index "<<i<<" ";
    //     cin>>arr[i];
    //     cout<<endl;
    // }
    // cout<<"Printing the arrays ";

    // for (int i = 0; i < n; i++)
    // {
    //    cout<<arr[i]<<" ";
    // }

    // double array

    int arr[10];
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Value in an array " << " ";
        cin >> arr[i];
    }
    //  double
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] * 2;
        cout << arr[i] << " ";
    }
}