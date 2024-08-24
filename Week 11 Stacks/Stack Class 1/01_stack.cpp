#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    // ctor
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
        }
        else
        {

            top--;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {

            return arr[top];
        }
    }

    int getSize()
    {
        return top + 1;
    }

    // there is no functionality of printing in stack but for our sack of understanding we are creation print
    void print()
    {
        cout << "Top: " << top << endl;
        cout << "Top Element: " << getTop() << endl;
        cout << "Stack: ";
        for (int i = 0; i < getSize(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << endl;
    }
};

int main()
{
    // // // Using STL
    // // Creation
    // stack<int> st;

    // // insertion
    // st.push(10);
    // st.push(20);
    // st.push(30);

    // // size check
    // cout << "Size: " << st.size() << endl;

    // // remove
    // st.pop();

    // // check empty
    // if (st.empty())
    // {
    //     cout << "Stack is Empty" << endl;
    // }
    // else
    // {
    //     cout << "Stack is Non-Empty" << endl;
    // }

    // // stack top
    // cout << "Top: " << st.top() << endl;

    // ****** FROM SCRATCH ******

    // Creation
    Stack st(8);

    // push
    st.push(10);
    st.print();
    st.push(20);
    st.print();
    st.push(30);
    st.print();

    //    // // pop
    //     st.pop();
    //     st.print();

    //     st.pop();
    //     st.print();

    //     st.pop();
    //     st.print();

    // top element
    cout << "Top element: " << st.getTop() << endl;
    // size of stack
    cout << "Size of Stack: " << st.getSize() << endl;
    cout << endl;

    // empty or not
    if (st.isEmpty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Not Empty" << endl;
    }

    return 0;
}