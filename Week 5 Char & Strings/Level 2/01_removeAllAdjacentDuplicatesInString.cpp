#include <iostream>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ans = "";
        int index = 0;

        while (index < s.length())
        {
            //    if same
            if (ans.length() > 0 && ans[ans.length() - 1] == s[index])
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(s[index]);
            }
            index++;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s;
    cout << "Enter Duplicate String: " << endl;
    cin >> s;

    cout << "Before: " << s << endl;
    string result = sol.removeDuplicates(s);

    cout << "After: " << result << endl;
}