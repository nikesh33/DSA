#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{')
            {
                // for open bracket -> just push
                st.push(ch);
            }
            else
            {
                // closing bracket
                if (!st.empty())
                {
                    if (ch == ')' && st.top() == '(')
                    {
                        st.pop();
                    }
                    else if (ch == '}' && st.top() == '{')
                    {
                        st.pop();
                    }
                    else if (ch == ']' && st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        // no match
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution solution;

    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";

    // Checking validity of each string
    cout << "Test 1: " << solution.isValid(test1) << endl; // Expected output: 1 (true)
    cout << "Test 2: " << solution.isValid(test2) << endl; // Expected output: 1 (true)
    cout << "Test 3: " << solution.isValid(test3) << endl; // Expected output: 0 (false)
    cout << "Test 4: " << solution.isValid(test4) << endl; // Expected output: 0 (false)
    cout << "Test 5: " << solution.isValid(test5) << endl; // Expected output: 1 (true)

    return 0;
}
