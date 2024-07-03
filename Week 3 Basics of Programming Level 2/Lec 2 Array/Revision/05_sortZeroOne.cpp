#include <iostream>
using namespace std;

void sortZeroOne(int arr[], int n)
{
    int oneCount = 0;
    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeroCount++;
        }
        if (arr[i] == 1)
        {
            oneCount++;
        }
    }

    // step 2 place all zero
    // int i;
    // for (i = 0; i < zeroCount; i++)
    // {
    //     arr[i] = 0;
    // }

    // for (int j = i; j < n; j++)
    // {
    //     arr[j] = 1;
    // }

    // way 2 Easy Way
    int index = 0;
    while (zeroCount--)
    {
        arr[index] = 0;
        index++;
    }

    while (oneCount--)
    {
        arr[index] = 1;
        index++;
    }
}

int main()
{
    int arr[] = {0, 1, 1, 1, 0, 0, 1, 0};
    int n = 8;

    sortZeroOne(arr, n);
    cout<<"{ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "}";
}