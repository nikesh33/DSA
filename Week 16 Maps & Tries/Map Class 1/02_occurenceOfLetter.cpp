#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

void countCharacters(unordered_map<char, int> &mapping, string str)
{

    // for (int i = 0; i < str.length(); i++)
    // {
    //     char ch = str[i];
    //     mapping[ch]++;
    // }

    for (auto i : str)
    {
        char ch = i;
        mapping[ch]++;
    }
}

int main()
{
    string str = "lovebbabbar";
    unordered_map<char, int> mapping;
    countCharacters(mapping, str);

    // for sorted ordered use map it will result an sorted manner ig-> a b c d e
    // map
    // map<char,int>mapping2;
    // countCharacters(mapping2,str);

    // traversal map
    for (auto i : mapping)
    {
        cout << i.first << "->" << i.second << endl;
    }

    return 0;
}