#include <iostream>
#include <string.h>
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

// Complexity => O(n) =>
bool checkPalindrome(char ch[], int n)
{
    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        if (ch[i] == ch[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    //    yaha tak aa gaye ho matalab sare character match hogye hai
    // iska matlab return true
    return true;
}

int main()
{

    // i/p => NOON
    // o/p => NOON
    // Valid or Invalid return karna hai

    char ch[100];
    cout << "Enter String: ";
    cin.getline(ch, 100);
    int length = findLength(ch, 100);
    bool ans = checkPalindrome(ch, length);
   
    if (ans == true)
    {
        cout << "Valid Pelindrome" << endl;
    }
    else
    {
        cout << "Not an Pelindrome";
    }
}