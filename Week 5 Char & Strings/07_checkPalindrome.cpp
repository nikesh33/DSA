#include <iostream>
#include <string.h>
using namespace std;


int findLength(char ch[],int size){
    int length = 0;
    while (ch[length]!='\0')
    {
        length++;
    }
    return length;
    
}
// Complexity => O(l) => L?=length of string //entire string traverse ho rha hai
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

    cin.getline(ch, 100);
    int length = findLength(ch,100);
    checkPalindrome(ch,length);
    cout << "After: " << ch;
}