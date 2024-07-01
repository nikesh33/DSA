#include <iostream>
using namespace std;

void countZeroOne(int arr[], int size)
{
    int zeroCount = 0;
    int oneCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            oneCount++;
        }
        else if (arr[i] == 0)
        {
            zeroCount++;
        }
    }
    cout << "Zero Count is: " << zeroCount << endl;
    cout << "One Count is: " << oneCount;
}

int main()
{
    int arr[] = {1, 1, 0, 1, 0,0,1,0,1,0};
    int size = 10;

    countZeroOne(arr, size);
}