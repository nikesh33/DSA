#include <iostream>
#include <limits.h>
using namespace std;

int findMin(int arr[], int size, int index, int mini)
{
    // base case
    if (index >= size)
    {
        return;
    }

    mini = min(mini, arr[index]);

    // recursive call
    findMin(arr, size, index+1, mini);
}

int main()
{
    int arr[] = {40, 20, 30, 10, 50};
    int size = 5;
    int index = 0;
    int mini = INT_MAX;
   findMin(arr, size, index, mini);
   cout<<"Minimum Number is: "<<mini;
}