#include <iostream>
using namespace std;

int main()
{
    // 1 take 10 size array
    // 2 take i/p in that array
    // 3 double-up each value in it

    int arr[10];
    int size = 10;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the Value in array at " << i << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]*2<<endl;
       
    }
    

    return 0;
}