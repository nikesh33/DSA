#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    // Pointer to an array
    // Normal
    int *ptr1 = arr;
    cout << *ptr1 << endl;
    // Pointer to an array
    int(*ptr)[5] = &arr;
    cout << (*ptr)[2] << endl;
}