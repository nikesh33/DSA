#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    // base case
    if (n == 0) // jab array khatam ho jayega
        return;

    // processig
    cout << *arr << " "; // 0th element

    // recursive call
    printArray(arr + 1, n - 1); // 0+1 = 1st element 8-1=7 ,7-1 =6, 6-1=5 , 4,3,2,1
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    printArray(arr, 8);
}