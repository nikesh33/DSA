#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of pattern for hallow square pattern ";
    cin >> size;
    for (int i = 0; i <= size; i++)
    {
        for (int row = 0; row < size; row++)
        {
            if (i == 0 || i == size)
            {
                /* code */
                cout << "*";
            }
else
            cout << " ";
        }
        cout << endl;
    }
}