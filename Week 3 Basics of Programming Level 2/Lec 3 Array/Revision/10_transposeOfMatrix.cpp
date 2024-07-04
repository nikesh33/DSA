#include <iostream>
using namespace std;

void transposeArray(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        // for (int j = 0; j <= i; j++)  //we can also use this if we want from lower traingle
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

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
    int arr[][4] = {{2, 4, 6, 1},
                    {8, 3, 5, 4},
                    {7, 9, 1, 7},
                    {2, 5, 6, 3}};
    int row = 4;
    int col = 4;
    cout << "Before Transpose: " << endl;
    printArray(arr, row, col);
    transposeArray(arr, row, col);
    cout << "After Transpose: " << endl;
    printArray(arr, row, col);
}