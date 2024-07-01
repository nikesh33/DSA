#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number ";
    cin >> n;
    // first
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << "*";
        }
        for (int i = 0; i < 2 * n - 2 * row - 2; i++)
        {
            cout << " ";
        }
        for (int j = 0; j < row + 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // second half
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n - row - 1 + 1; col++)
        {
            cout << "*";
        }
        for (int i = 0; i < row * 2; i++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - row - 1 + 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}