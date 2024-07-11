#include <iostream>
#include <string.h>
using namespace std;

void converToUpperCase(char ch[]){
    int index = 0;

    while (ch[index]!='\0')
    {
        char currCharacter = ch[index];
        // checking if lowerCase then convert yo uppercase
        if (currCharacter>='a'&& currCharacter<='z')
        {
           ch[index] = currCharacter-'a'+'A';
        }
        index++;
    }
    
}

int main()
{
    char ch[100];

    cin.getline(ch,100);

    cout<<"Printing Before: "<<ch<<endl;

    converToUpperCase(ch);

     cout<<"Printing After: "<<ch<<endl;
}
