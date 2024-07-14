#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkPalindrome(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                // s[i] != s[]
                // 1 removal allowed
                // check palindrome for remaining string after removal

                // ith character => remove
                bool ans1 = checkPalindrome(s, i + 1, i);
                // jth character => remove
                bool ans2 = checkPalindrome(s, i, j - 1);

                return ans1 || ans2;
            }
        }
        // agar yaha tak aa gye ho to palindrome hai
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "racecar";

    bool ans = sol.checkPalindrome(s, 0, s.length() - 1);

    if (ans == true)
    {
        cout << "Valid Palindrome";
    }
    else
    {
        cout << "Not a Valid Palindrome";
    }
}