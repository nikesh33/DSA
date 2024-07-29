#include <iostream>
using namespace std;

void findSubsequences(string str, string output, int index)
{
    // base case
    if (index >= str.length())
    {
        // ans vo output string me build ho chuka hai
        // print kardo
        cout << "->" << output << endl;
        return;
    }

    char ch = str[index];

    // pehle exclude kiya phir include
    // // exclude
    // findSubsequences(str, output, index + 1);
    // // include
    // // output string me ch charcter ko include kardo
    // output.push_back(ch);
    // findSubsequences(str, output, index + 1);

    // pehle include kiya phir exclude

    // include
    output.push_back(ch);
    findSubsequences(str, output, index + 1);

    // exlude
    output.pop_back();
    findSubsequences(str, output, index + 1);
}

int main()
{
    string str = "abc";
    string output = " ";
    int index = 0;

    findSubsequences(str, output, index);
}