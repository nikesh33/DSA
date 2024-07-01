#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter";
    cin >> n;

    // first half
    for (int i = 0; i < n; i++)
    {
        for (int col = 0; col < n - i; col++)
        {
            cout << "*";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << " ";
        }
        for (int l = 0; l < n - i; l++)
        {
            cout << "*";
        }

        cout << endl;
    }
    // another half
    for (int row = 1; row < n; row++)
    {
        for (int j = 0; j < row + 1; j++)
        {
            cout << "*";
        }
        for (int k = 0; k < 2*n-2*row-1; k++)
        {
            cout<<" ";
        }
        for (int l = 0; l < row+1; l++)
        {
            cout<<"*";
        }
        
      
    cout << endl;
    }
}