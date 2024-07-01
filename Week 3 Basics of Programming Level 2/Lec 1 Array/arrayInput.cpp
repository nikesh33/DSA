#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int n = 5;
    // taking input
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the values of index " << i << ": ";
        cin >> arr[i];
    }

    // printing the array
    cout << "Printing the array " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}