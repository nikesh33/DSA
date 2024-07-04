#include <iostream>
#include <limits.h>
using namespace std;

int maxNum(int arr[][4], int row, int col)
{
    int max = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

// Minimum Ans function
int minNum(int arr[][4], int row, int col)
{
    int minAns = INT_MAX;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] < minAns)
            {
                minAns = arr[i][j];
            }
        }
    }
    return minAns;
}

int main()
{
    int arr[3][4];

    //  initialize
    int row = 3;
    int col = 4;

    // insert value in array
    cout << "Insert Values in Array Row Wise: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    // function maxNum
    cout << "Maximum Ans: " << maxNum(arr, row, col)<<endl;
    cout << "Minimum Ans: " << minNum(arr, row, col);
}