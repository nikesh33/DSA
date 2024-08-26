#include <iostream>
#include <stack>
using namespace std;

bool checkRedundant(string &str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int operatorCount = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    operatorCount++;
                }
                st.pop();
            }

            // yaha par tabhi pahochoge jab
            // aapke stack k top par ek opening bracket hoga
            st.pop();
            if (operatorCount == 0)
            {
                return true;
            }
        }
    }
    // agara main yaha tak pahuvha hu iska matlab hai har ek bracket k pair k bich me
    // ek operator pakka mila hoga
    return false;
}

int main()
{
    string str = "(((a+b)*(c+d)))";
    bool ans = checkRedundant(str);

    if (ans == true)
    {
        cout << "Redundant Brackets Present" << endl;
    }
    else
    {
        cout << "Redundant Brackets Not Present" << endl;
    }

    return 0;
}
