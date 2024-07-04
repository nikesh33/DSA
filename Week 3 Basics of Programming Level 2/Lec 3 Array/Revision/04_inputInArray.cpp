// 2D Array Me input kaise le?
#include <iostream>
using namespace std;

int main()
{
    int arr[3][3];
    int row = 3;
    int col = 3;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // row wise input
            // cin >> arr[i][j];
            // // col wise input
            // cin >> arr[j][i];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // row wise output
            cout << arr[i][j] << " ";
            // // col wise output
            // cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}