#include <iostream>
using namespace std;

// searching ka basic function jo ki linearly har element search kar rhe
bool findTarget(int arr[][3], int row, int col, int target)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                // if found return true
                return true;
            }
        }
    }
    // target nhi mila hoga tabhi yaha aa sakte ho
    return false;
}

int main()
{
    int arr[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    int row = 3;
    int col = 3;
    int target;

    cout << "Enter Target: ";
    cin >> target;

    bool finalAns = findTarget(arr, row, col, target);
    if (finalAns == 1)
    {
        cout << "Its Present";
    }
    else
    {
        cout << "It's Absent";
    }
}