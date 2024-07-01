#include <iostream>
using namespace std;

void countZeroOne(int arr[], int size)
{
    int one = 0;
    int zero = 0;

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
    cout << "One Count: " << one << endl;
    cout << "Zero Count: " << zero;
}

int main()
{
    int arr[8] = {0, 1, 0, 1, 0, 0, 1, 1};
    int n = 8;

    // int one = 0;
    // int zero = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == 0)
    //     {
    //         zero = zero + 1;
    //     }
    //     else if (arr[i] == 1)
    //     {
    //         one = one + 1;
    //     }
    // }
    // cout << "Zero is " << zero << endl;
    // cout << "One is " << one;

    // way 2 =>>
    countZeroOne(arr, n);
}