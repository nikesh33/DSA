#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    // static
    // int arr[5]={1,2,3,4,5};

    // dynamic
    int n;
    cout<<"Enter Size of the array"<<": ";
    cin >> n;
    int *arr = new int[n];
        cout<<"Enter Value of the array"<<endl;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        arr[i] = data;
    }

    // print
    cout<<"the given array is: ";
    print(arr,n);
}