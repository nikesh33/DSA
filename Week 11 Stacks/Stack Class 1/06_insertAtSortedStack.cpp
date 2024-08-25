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

void insertSorted(stack<int> &st, int element)
{
    // base case
    if (st.empty() || element > st.top())
    {
        st.push(element);
        return;
    }

    // 1 case
    int temp = st.top();
    st.pop();

    // rc
    insertSorted(st, element);

    // backtracking
    st.push(temp);
}

void sortStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }
    // 1 case
    int temp = st.top();
    st.pop();

    // rc
    sortStack(st);

    // backtrack
    insertSorted(st,temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(7);
    st.push(12);
    st.push(5);
    st.push(11);
    // int element = 25;
    // insertSorted(st, element);

    sortStack(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}