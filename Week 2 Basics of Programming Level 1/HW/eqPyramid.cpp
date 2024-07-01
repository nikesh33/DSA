#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter Size ";
    cin >> size;
    int k = size;

    for (int row = 0; row < size; row++)
    {
        int c = 1;
        for (int col = 0; col < k; col++)
        {
            if (col < size - row - 1)
            {
                cout << " ";
            }
            else if (col <= size - 1)
            {
                cout << c;
                c++;
            }
            else if (col == size)
            {
                c=c-2;
                cout << c;
                c--;
            }
            else{
                cout<<c;
                c--;
            }
        }
        k++;

        cout << endl;
    }
}