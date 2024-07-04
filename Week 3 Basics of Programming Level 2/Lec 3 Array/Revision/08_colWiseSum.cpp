#include <iostream>
using namespace std;

// colwise sum function
void colSum(int arr[][4], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum = sum + arr[j][i];
        }
        cout << "Column Wise Sum: " << sum << endl;
    }
}

int main()
{
    int arr[][4] = {{1, 2, 3, 4},
                    {2, 2, 2, 2},
                    {5, 5, 5, 5}};
    int row = 3;
    int col = 4;

    colSum(arr, row, col);
}