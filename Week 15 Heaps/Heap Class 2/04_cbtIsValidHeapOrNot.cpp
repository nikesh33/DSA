#include <iostream>
#include <queue>
#include <climits> // For INT_MIN
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

// If you don't want to use pair => pair<int,bool>;
// use your own class like this
class Info
{
public:
    int maxVal;
    bool isHeap;

    Info(int a, bool b)
    {
        this->maxVal = a;
        this->isHeap = b;
    }
    // Default constructor
    Info() : maxVal(INT_MIN), isHeap(true) {}
};

Info checkMaxHeap(Node *root)
{
    if (root == NULL)
    {
        Info temp;
        temp.maxVal = INT_MIN;
        temp.isHeap = true;
        return temp;
    }
    if (root->left == NULL && root->right == NULL)
    {
        Info temp;
        temp.maxVal = root->data;
        temp.isHeap = true;
        return temp;
    }

    Info leftAns = checkMaxHeap(root->left);
    Info rightAns = checkMaxHeap(root->right);

    // 1 Case mujhe solve karna hai
    if (root->data > leftAns.maxVal && root->data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap)
    {
        Info ans;
        ans.maxVal = root->data;
        ans.isHeap = true;
        return ans;
    }
    else
    {
        Info ans;
        ans.maxVal = max(root->data, max(leftAns.maxVal, rightAns.maxVal));
        ans.isHeap = false;
        return ans;
    }
}

int main()
{
    // Constructing the following tree:
    //          10
    //        /    \
    //       9      8
    //      / \    / \
    //     7   6  5   4
    //    / \
    //   3   2

    Node *root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);

    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    root->left->left->left = new Node(3);
    root->left->left->right = new Node(2);

    // Call checkMaxHeap function to check if this tree is a max-heap
    Info result = checkMaxHeap(root);

    if (result.isHeap)
    {
        cout << "The given binary tree satisfies the Max-Heap property." << endl;
    }
    else
    {
        cout << "The given binary tree does NOT satisfy the Max-Heap property." << endl;
    }

    return 0;
}