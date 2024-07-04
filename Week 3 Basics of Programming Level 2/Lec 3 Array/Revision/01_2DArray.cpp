//  2D Array => int arr[row][col];
// int arr[5][10];
// 1D Array => int arr[5];

#include <iostream>
using namespace std;

// function for printing (Note always tell col in input para in function)

void printArray(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // 2D array
    //  int arr[5][10];
    // eg-
    // int arr[100][1000];

    // Initilize
    // int arr[2][4] = {
    //     {10, 20, 30, 40},
    //     {90, 80, 70, 60}};

    // // one more example
    // int arr2[4][3] = {
    //     {1, 2, 3},
    //     {5, 6, 7},
    //     {9, 10, 11},
    //     {12, 13, 14}};

    // // Access
    // int arr4[2][3] = {{10, 20, 30},
    //                   {40, 50, 60}};

    //                   cout<<arr4[1][2];

    // coversion of 2d array to 1d array
    // formula = Total_Column*(row ka index -i) + (col ka index-j)
    // i.e = C*i+j

    /*************How to Print 2D Array *****************/

    int arr[][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12}};

    int row = 3;
    int col = 4;

    printArray(arr, row, row);
}