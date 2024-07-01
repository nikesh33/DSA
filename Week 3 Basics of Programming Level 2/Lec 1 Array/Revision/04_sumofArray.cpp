#include <iostream>
using namespace std;

int main()
{
    // init 5 size array
    // take 5 i/p
    // total sum print

    int arr[5];
    int n = 5;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value in array: ";
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        temp = temp + arr[i];
    }
    cout << temp;
}