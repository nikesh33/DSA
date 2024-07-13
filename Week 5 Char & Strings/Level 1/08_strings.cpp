#include <iostream>
using namespace std;

int main()
{
    // string name;
    // What is String => Sequence of Character (Collection of character)
    // Creation of string
    // string => Datatype
    // name => Variable

    // char array bhi to same hota hai?
    // Nahi char ch[10] => ye static in nature hota hai

    // string is dynamic in nature
    // string jo hota hai wo runtime pe bhi dynamically change ho sakti hai like Vector
    // there are utility function for string manupulation

    // Coding Part

    // Creating
    string name;

    // input
    // cin >> name;
    getline(cin, name);

    // print
    // cout << "Printing Name: " << name << endl;

    // cout << "Printing first Character: " << name[0] << endl;

    int index = 0;
    while (name[index] != '\0')
    {
        cout << "Index: " << index << " Character: " << name[index] << endl;
        index++;
    }

    // eg-Nikesh
    cout << "Printing Null Value at 6th Location: " << name[6] << endl; // expected 'Nothing'

    int value = (int)name[6];
    cout << "Printing ASCII Value for Null Character: " << value << endl; // expected 0
}