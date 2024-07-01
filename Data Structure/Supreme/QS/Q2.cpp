#include <iostream>
using namespace std;

int main()
{
    // create array of size 5
    int arr[5];
    int n = 5;
    // take input
    for (int i = 0; i < n; i++)
    {
        cout << "Pls enter the values: ";
        cin >> arr[i];
    }

    //  sum
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
       sum = sum+arr[i];
    }
    cout<<sum;
    
}