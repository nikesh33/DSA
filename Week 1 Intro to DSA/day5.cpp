#include <iostream>
using namespace std;

int main()
{
    int input;
    cout << "Enter Size: ";
    cin >> input;

    // for (int row = 0; row < input; row++)
    // {
    //     int total = input - 1;
    //     for (int col = 0; col < input - row; col++)
    //     {
    //         if (row == 0 || row == input - 1)
    //         {
    //             cout << "*";
    //         }
    //         else
    //         {
    //             if (col == 0 || col == input - row-1 )
    //             {
    //                 cout << "*";
    //             }
    //             else{
    //                 cout<<" ";
    //             }
    //         }
    //     }
    //     cout << endl;
    // }

    // 2

    for (int row = 0; row < input; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << row + 1;
        }
        if(col==0 || col== )
        cout << endl;
    }
}