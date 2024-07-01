#include <iostream>
using namespace std;
#include <limits.h>

int minNum(int arr[], int size)
{
    cout<<"IM in Function"<<"\n";
    // min ans store
    int minAns = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < minAns)
        {
            minAns = arr[i];
        }
    }
    return minAns;
}

int main()
{
    int arr[] = {2, -3, 9, 32, 11};
    int size = 5;

    int min = minNum(arr, size);
    cout<<"Minimum Answer is: " << min;
}