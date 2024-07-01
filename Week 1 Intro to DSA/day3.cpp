#include <iostream>
using namespace std;

int main()
{
    // int n;
    // cout << "Enter size" << endl;
    // cin >> n;

    // // outter
    // for (int row = 0; row < n; row++)
    // {
    //     // space
    //     for (int col = 0; col < n - row - 1; col++)
    //     {
    //         cout << " ";
    //     }

    //     // star
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         if (col == 0 || col == row + 1 - 1)
    //         {

    //             cout << "* ";
    //         }
    //         else
    //         {
    //             cout << "  ";
    //         }
    //     }
    //     cout << endl;
    // }

    // 2nd

    int n;
    cout << "Enter size" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < 2 * (n - i) - 1; j++)
        {
            if (j == 0 || j == 2 * (n - i) - 2)
            {
                /* code */
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}