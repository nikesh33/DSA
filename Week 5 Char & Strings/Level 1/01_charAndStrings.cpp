#include <iostream>
using namespace std;

int main()
{
    // // creation of array in char
    // char ch[5];

    // // taking Char Input In array
    // cin >> ch;

    // // printing char
    // cout << ch;
    // // access char
    // cout << ch[2];

    // Strings?=> Sequence of characters
    // eg = dog => [d|o|g|'\o'|
    // '\o' => (null character)=>(termination of strings) after string end like dog after g it will stop

    // // another code
    // char ch[10];
    // cin >> ch;
    // // printig using for loop
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "At Index: " << i << " " << ch[i] << endl;
    // }

    // char temp = ch[6];
    // // implicit typecasting
    // int value = (int)temp;
    // // "\0" hoga to uska ascii value 0 hota hai
    // cout << "Printing interger value: " << value << endl;

    // another code
    char ch[10];
    // cin >> ch;
    cin.getline(ch, 100);
    cout << "Printing the value of ch: " << ch << endl;

    // delimeter in cin
}