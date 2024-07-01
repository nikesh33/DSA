#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number " << endl;
    cin >> n;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < 2 * n - row - 2; col++)
        {
            cout << "*";
        }
        // number
        for (int k = 0; k < 2 * row + 1; k++)
        {
           if (row==0)
           {
               cout<<row+1;
           }
           else if(row>=1){
             cout << row+1 ;
           }
           
        }
        for (int l = 0; l < 2 * n - row; l++)
        {
            cout << "*";
        }

        cout << endl;
    }
}