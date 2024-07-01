#include <iostream>
using namespace std;

int main()
{
    // create 10 size array 
    int arr[10];
    int n = 10;
    // taking input in array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=2*arr[i];
         cout<<arr[i]<<" ";
    }
   
}