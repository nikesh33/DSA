#include <iostream>
using namespace std;

class Solution
{
public:
    int expand(string s, int i, int j)
    {
        int count = 0;

        while (i >= 0 && j < s.length() && s[i] == s[j])
        {
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s)
    {
        int totalCount = 0;

        for (int center = 0; center < s.length(); center++)
        {
            // Odd
            int oddAns = expand(s, center, center);

            // Even
            int evenAns = expand(s, center, center + 1);

            totalCount = totalCount + oddAns + evenAns;
        }
        return totalCount;
    }
};

int main()
{
    Solution sol;

    string str = "madam";

    // odd ka ans = 7;
    // even ka ans = 0
    // totalans = totalAns+odd+even;
    cout << sol.countSubstrings(str);
}