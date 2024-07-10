#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int findLength(char ch[], int size)
{
    int length = 0;
    while (ch[length] != '\0')
    {
        length++;
    }
    return length;
}

// // complexity 0(n)
void reverseStr(char ch[], int n)
{

    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        swap(ch[i], ch[j]);
        i++;
        j--;
    }
}

int main()
{
    char ch[100];
    cout << "Enter a String: ";
    cin >> ch;
    cout << "Before: " << ch << endl;
    int len = findLength(ch, 100);
    reverseStr(ch, len);
    cout << "After: " << ch << endl;
}