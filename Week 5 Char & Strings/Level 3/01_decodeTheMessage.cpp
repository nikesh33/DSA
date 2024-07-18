#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string decodeMessage(string key, string message)
    {

        // create mapping
        char start = 'a';
        char mapping[280] = {0};

        for (auto ch : key)  //ch=> har character ke liye chalega in (key) eg-run => r u n 
        {
            if (ch != ' ' && mapping[ch] == 0)
            {
                mapping[ch] = start;
                start++;
            }
        }

        // use mapping
        string ans;
        for (auto ch : message)
        {
            if (ch == ' ')
            {
                ans.push_back(' ');
            }
            else
            {
                char decodedChar = mapping[ch];
                ans.push_back(decodedChar);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    cout << sol.decodeMessage(key, message) << endl;

    return 0;
}