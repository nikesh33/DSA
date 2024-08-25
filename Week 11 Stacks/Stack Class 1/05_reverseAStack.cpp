#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int &element)
{
    // base case
    if (st.empty())
    {
        st.push(element);
        return;
    }

    // 1 case main karuga
    int temp = st.top();
    st.pop();

    // baaki ka recursion
    insertAtBottom(st, element);

    // backtracking
    st.push(temp);
}

void reverseStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }

    // 1 case main karuga
    int temp = st.top();
    st.pop();

    // baaki ka recursion
    reverseStack(st);

    // backtracking
    insertAtBottom(st, temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Withot Reverse: " << endl;
    // 30 20 10

    reverseStack(st);
    cout << "With Reverse: " << endl;

    while (!st.empty())
    { 
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}