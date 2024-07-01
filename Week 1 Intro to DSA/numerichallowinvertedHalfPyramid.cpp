#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter Size: ";
    cin >> size;

    for (int row = 0; row < size; row++)
    {
        for (int col = row+1; col <= size; col++)
        {
            //    cout<<col+1;
            if ( col == row + 1 || col == size || col == 0  )
            {
                cout << col;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}