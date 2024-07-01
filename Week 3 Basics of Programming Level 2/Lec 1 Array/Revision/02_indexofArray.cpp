// Indexing in Array
// why need of index ? => To access the address we need index
// 0 based indexing

#include <iostream>
using namespace std;

int main()
{
    // int arr[5] = {5, 8, 2, 1, 8};

    // How to access values in array
    // arr[index] //index = 0,1,2,...,n
    // cout<<arr[0]<<" "<<arr[3]; //5 1
    // int n = 5;

    // // printing array
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "ON index " << i << ":" << arr[i] << endl;
    // }

    // taking input in array and printing the array
    int arr[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the value for index: " << i << " ";
        cin >> arr[i];
    }

    cout << "Printing the array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    // formula
    /* arr[i] =>
       value at(base Address + (data type*index))
eg=
     adress       104 108 112 116 120
    int arr[4] = {10 ,20, 30, 40, 70}
    104+4*2 = 112  address 112 ko jo value hoga wo milega => i.e 30
    //    jo address pe wo value padi hai wo pakda dena
    */

    return 0;
}
