#include <iostream>
using namespace std;

void print1(int arr[][3], int row, int col)
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
    // // //  1d
    // // int arr[5];
    // // // 2d
    // // int arr[5][2]; // where 5 is row and 2 is column
    // // // with values
    // int arr[5][3] = {{10, 20, 30},
    //                  {1, 2, 3},
    //                  {0, 2, 1},
    //                  {100, 200, 300},
    //                  {1, 1, 1}};

    // int row = 5;
    // int col = 3;
    // print1(arr, row, col);

    // Input
    int arr[3][3];
    int row = 3;
    int col = 3;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter the Input for row index: " << i << " Enter the Input for col index: "<<j << endl;
            cin >> arr[i][j];
        }
    }

    cout << "Succes";

    return 0;
}