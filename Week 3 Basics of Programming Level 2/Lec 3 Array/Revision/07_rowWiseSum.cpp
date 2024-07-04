#include <iostream>
using namespace std;

// sum function
void getSum(int arr[][4], int row, int col)
{
    // Note -  When We declare int sum = 0; here(Global Scope) this will result to different ans due to it will not reset the value to 0  so it will give sum of all the element in array

    for (int i = 0; i < row; i++)
    {
        // Note - When we declare this here after every row it will get reset to 0 so it will give row wise sum
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum << endl;
    }
}

int main()
{
    int arr[3][4];
    int row = 3;
    int col = 4;

    cout << "Insert Value in Array Row Wise: ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Calling Function
    getSum(arr, row, col);
}