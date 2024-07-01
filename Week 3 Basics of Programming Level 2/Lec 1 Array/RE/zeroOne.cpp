#include <iostream>
using namespace std;

void countZeroOne(int arr[], int size)
{
    int zero = 0;
    int one = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zero++;
        }
        else if (arr[i] == 1)
        {
            one++;
        }
    }

    cout << "ZeroCount: " << zero << endl;
    cout << "oneCount: " << one << endl;
}

int main()
{
    int arr[] = {0, 0, 0, 1, 1, 0, 1, 0, 0, 1,1,1,0};
    int size = 13;
    // zero -> 6
    // one -> 4

    countZeroOne(arr, size);
}