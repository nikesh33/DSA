#include <iostream>
#include <string.h>
using namespace std;

// Complexity => O(l) => L?=length of string //entire string traverse ho rha hai
void replaceCharacter(char ch[])
{
    int index = 0;
    while (ch[index] != '\0')
    {
        char curr = ch[index];
        if (curr == '@')
        {
            ch[index] = ' ';
        }
        index++;
    }
}

int main()
{
    // my@Name@NikeshVishwa@karma
    // my Name Nikesh Vishwakarma

    char ch[100];

    cin.getline(ch, 100);
    replaceCharacter(ch);
    cout << "After: " << ch;
}