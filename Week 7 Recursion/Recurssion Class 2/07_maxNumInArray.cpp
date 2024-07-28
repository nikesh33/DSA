#include <iostream>
#include <limits.h>
using namespace std;

void getMax(int arr[], int size, int index, int &maxi)
{
    // base case
    if (index >= size)
    {
        return;
    }

    // processing
    maxi = max(maxi, arr[index]);
    // rc
    getMax(arr, size, index + 1, maxi);
}

int main()
{
    int arr[] = {10, 20, 80, 40, 50};
    int size = 5;
    int index = 0;
    int maxi = INT_MIN;
    getMax(arr, size, index, maxi);
    cout << maxi << " ";
}