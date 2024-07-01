#include <iostream>
using namespace std;

int main()
{
    // //
    // int size;
    // cout << "Enter the Size of Pattern To Be Printed " << endl;
    // cin >> size;

    // // for star
    // for (int i = 0; i <= size; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // int size;
    // cout<<"Enter the Size of Pattern "<<endl;
    // cin>>size;

    // for (int i = 0; i < size; i++)
    // {
    //     for (int row = 0; row < (size -i)-1; row++)
    //     {
    //         cout<<" ";
    //     }
    //     for (int col = 0; col <=i; col++)
    //     {
    //        cout<<"* ";
    //     }

    //     cout<<endl;
    // }

    // int size;
    // cout << "Enter Total Size " << endl;
    // cin >> size;

    // for (int i = 0; i < size; i++)
    // {
    //     for (int row = 0; row < size - i; row++)
    //     {
    //         /* code */
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // int size;
    // cout << "Enter Total Size " << endl;
    // cin >> size;

    // for (int i = 0; i < size; i++)
    // {
    //     // for space
    //     for (int row = 0; row < i; row++)
    //     {
    //         /* code */
    //         cout << " ";
    //     }

    //     // for star
    //     for (int row = 0; row < size - i; row++)
    //     {
    //         /* code */
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // int size;
    // cout << "Enter Total Size " << endl;
    // cin >> size;

    // for (int i = 0; i < size; i++)
    // {
    //       // for white space
    //     for (int col = 0; col < i + 1; col++)
    //     {
    //         cout << " ";
    //     }

    //     /* code */
    //     for (int row = 0; row < size - i; row++)
    //     {
    //         cout << "* ";
    //     }

    //     cout << endl;
    // }

    // // Rhombus
    // int size;
    // cout << "Enter Total Size " << endl;
    // cin >> size;

    // for (int i = 0; i < size; i++)
    // {

    //     for (int col = 0; col < i; col++)
    //     {
    //         /* code */
    //         cout << " ";
    //     }

    //     for (int row = 0; row < size - 1; row++)
    //     {
    //         cout << "* ";
    //     }

    //     cout<<endl;
    // }

    // // Diamond Pattern
    // int size;
    // cout << "Enter Total Size " << endl;
    // cin >> size;

    // for (int i = 0; i <= size; i++)
    // {
    //     // for space
    //     for (int row = 0; row < size - i; row++)
    //     {
    //         cout << " ";
    //     }

    //     // for star
    //     for (int col = 0; col < i; col++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i <= size; i++)
    // {
    //     for (int row = 0; row < i; row++)
    //     {
    //         cout << " ";
    //     }
    //     for (int col = 0; col < size-i; col++)
    //     {
    //         if (col == 0)
    //         {
    //             cout<<" ";
    //         }
    //         else
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // Hourglass Pattern
    int size;
    cout << "Enter Total Size " << endl;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (int k = 0; k < size - i; k++)
        {
            cout << "* ";
        }

        cout << endl;
    }
//another half
    for (int i = 2; i <= size; i++)
    {
        for (int j = 1; j < size - i + 1; j++) // 4 --> 3 //4-1 =3 4
        {
            // space
            if (j==1)
            {
                /* code */
               
            }
            
            cout << " ";
        }

        for (int k = 0; k < i; k++)
        {
            /* code */
            cout << "* ";
        }

        cout << endl;
    }
}