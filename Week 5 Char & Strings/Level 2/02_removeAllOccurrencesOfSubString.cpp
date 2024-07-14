#include <iostream>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        while (s.find(part) != string::npos)
        {
            // if inside loop, it means that part exists in s string
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main()
{
    Solution sol;
    // string
    // string fullPart = "Hey there is side Nikesh here";
    // string part = "is side";
    string s = "axxxxyyyyb";
    string part = "xy";

    string result = sol.removeOccurrences(s, part);
    cout << result << endl;
    // Expected >> ab
}