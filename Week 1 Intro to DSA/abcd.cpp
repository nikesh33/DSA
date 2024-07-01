#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter Size ";
    cin >> size;

    for (int row = 0; row < size; row++)
    {
        char ch;
        for (int col = 0; col < row + 1; col++)
        {
            /* code */
            int number = col + 1;
            ch = number + 'A' - 1;
            cout << ch << " ";
        }

        for (char alphabet = ch; alphabet > 'A';)
        {
            alphabet--;
            cout << alphabet << " ";
        }

        cout << endl;
    }
}