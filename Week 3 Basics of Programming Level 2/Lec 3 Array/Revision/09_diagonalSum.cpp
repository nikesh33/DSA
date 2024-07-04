#include <iostream>
using namespace std;

int main()
{
    int arr[4][4] = {{10, 20, 30, 40},
                     {50, 40, 30, 20},
                     {11, 12, 13, 14},
                     {21, 20, 10, 11}};
    int row = 4;
    int col = 3;

    int sum = 0;
    cout << "Diagonal: ";
    for (int i = 0; i < row; i++)
    {
        sum = sum + arr[i][i];
        cout << arr[i][i] << " ";
    }
    cout << endl;
    cout << "Sum of Diagonal: " << sum << endl;
}