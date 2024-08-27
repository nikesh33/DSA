#include <iostream>
#include <vector>
using namespace std;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack
{
public:
    vector<pair<int, int>> st;

    MinStack() {}

    void push(int val)
    {
        if (st.empty())
        {
            // it means i am inserting first element
            pair<int, int> p;
            p.first = val;
            p.second = val;
            st.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            int puranaMin = st.back().second;
            p.second = min(puranaMin, val);
            st.push_back(p);
        }
    }

    void pop() { st.pop_back(); }

    int top()
    {
        pair<int, int> rightMostPair = st.back();
        return rightMostPair.first;
    }

    int getMin()
    {
        pair<int, int> rightMostPair = st.back();
        return rightMostPair.second;
    }
};

int main()
{
    // Create a MinStack object
    MinStack *minStack = new MinStack();

    // Push elements onto the stack
    minStack->push(5);
    minStack->push(3);
    minStack->push(7);
    minStack->push(2);

    // Print the minimum element in the stack
    cout << "Minimum Element: " << minStack->getMin() << endl;

    // Pop an element and print the top element
    minStack->pop();
    cout << "Top Element after pop: " << minStack->top() << endl;

    // Print the minimum element in the stack after pop
    cout << "Minimum Element after pop: " << minStack->getMin() << endl;

    // Clean up
    delete minStack;

    return 0;
}