#include <iostream>
using namespace std;

bool findTarget(int arr[][3], int row, int col, int target)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int arr[][3] = {{1, 2, 3}, {2, 4, 6}, {4, 8, 16}};
    int row = 3;
    int col = 3;
    int target = 4;

    cout << "True or False: " << findTarget(arr, row, col, target) << endl;
}