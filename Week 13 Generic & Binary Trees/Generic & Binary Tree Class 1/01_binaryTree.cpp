#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// it returns root node of the created tree
Node *createTree()
{
    cout << "Enter the Value for Node: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    // Step1 : Create a Node
    Node *root = new Node(data);

    // Step2 : Create Left SubTree
    cout << "Left Node: " << root->data << endl;
    root->left = createTree();
    // Step3 : Create Right SubTree
    cout << "Right Node: " << root->data << endl;
    root->right = createTree();

    return root;
}

void preOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // N L R
    // N
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

void inorderTraversal(Node *root)
{
    // L N R
    // Base case
    if (root == NULL)
    {
        return;
    }

    // L
    inorderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    // L R N
    // Base case
    if (root == NULL)
    {
        return;
    }

    // L
    postorderTraversal(root->left);
    // R
    postorderTraversal(root->right);
    // N
    cout << root->data << " ";
}

int main()
{
    Node *root = createTree();
    cout << root->data << endl;

    return 0;
}