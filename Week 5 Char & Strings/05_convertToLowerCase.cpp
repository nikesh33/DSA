#include <iostream>
#include <string.h>
using namespace std;

void converToUpperCase(char ch[])
{
    int index = 0;

    while (ch[index] != '\0')
    {
        int currentChar = ch[index];
        if (currentChar >= 'A' && currentChar <= 'Z')
        {
            ch[index] = currentChar - 'A' + 'a';
        }
        index++;
    }
}

int main()
{
    char ch[100];
    cin.getline(ch, 100);

    cout << "Before: " << ch << endl;
    converToUpperCase(ch);
    cout << "After: " << ch << endl;
}
