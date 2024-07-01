#include <iostream>
using namespace std;

void sortZeroOne(int arr[], int size)
{

    int zeroCount = 0;
    int oneCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)

            zeroCount++;

        if (arr[i] == 1)

            oneCount++;
    }
    //    new
    int i;
    for (i = 0; i < zeroCount; i++)
    {
        arr[i] = 0;
    }

    for (int j = i; j < size; j++)
    {
        arr[j] = 1;
    }
}

int main()
{
    int arr[10] = {0, 1, 0, 1, 1, 0, 0, 0, 0,1};
    int size = 10;

    sortZeroOne(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}