#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int total = i + 1;
        for (int j = 0; j < total; j++)
        {

            if (j == total - 1)
            {
                cout << i + 1;
            }
            else
            {
                /* code */
                cout << i + 1 << "*";
            }

            // if (j % 2 == 1)
            // {
            //     cout << "*";
            // }
            // else
            // {
            //     cout << i+1;
            // }
        }

        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        int total = 3;
        for (int j = 0; j < n-i-1; j++)
        {
            if ()
            {
                
            }
            
        }
        cout << endl;
    }
}