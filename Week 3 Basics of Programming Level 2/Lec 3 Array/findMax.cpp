#include <iostream>
#include <limits.h>
using namespace std;

int findMax(int arr[][4], int row, int col)
{
    int maxAns = INT_MIN;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] < maxAns)
            {
                maxAns = arr[i][j];
            }
        }
    }
    return maxAns;
}

int main()
{
}