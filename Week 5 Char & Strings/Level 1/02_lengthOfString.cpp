#include <iostream>
#include <string.h>
using namespace std;

int findLength(char ch[], int size)
{
    // int lenght = 0;
    int index = 0;

    // using while loop
    while (ch[index] != '\0')
    {
        // lenght++;
        index++;
    }
    return index;

    //// using <for loop>
    // for (int i = 0; i < size; i++)
    // {
    //     if (ch[i] == '\0')
    //     {
    //         //    ruk jao
    //         break;
    //     }
    //     else
    //     {
    //         lenght++;
    //     }
    // }
    // return lenght;
}

int main()
{
    char ch[100];

    // cin >> ch;
    cin.getline(ch, 100);

    int len = findLength(ch, 100);

    cout << "Length of string is: " << len << endl;
    cout << "Printing length using strlen: " << strlen(ch) << endl; //<string.h>
}