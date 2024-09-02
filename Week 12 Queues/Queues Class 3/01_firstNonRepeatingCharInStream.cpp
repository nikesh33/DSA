#include <iostream>
#include <queue>
using namespace std;

int main()
{
    string str = "ababc";
    queue<char> q;
    int freq[26] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        freq[ch - 'a']++; // mapping of a to 0 b to 1 c to 2
        q.push(ch);

        // answer find karo
        while (!q.empty())
        {
            char frontCharacter = q.front();
            if (freq[frontCharacter - 'a'] > 1)
            {
                // yaani ye answer nahi hai
                q.pop();
            }
            else
            {
                // ==  1 wala case
                // yahi answer hai
                cout << frontCharacter << "->";
                break;
            }
        }

        if (q.empty())
        {
            // loi answer nahi nikla
            cout << "#" << "->";
        }
    }

    return 0;
}