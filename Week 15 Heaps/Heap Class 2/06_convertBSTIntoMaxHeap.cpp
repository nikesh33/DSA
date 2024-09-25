#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node *&root)
{
    // cout << "Enter data: " << endl;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        // cout << "Enter data: " << endl;
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    // Asli traversal start karte hai

    // while (!q.empty())
    // while (q.size() > 1)
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {

                q.push(NULL);
            }
        }
        else
        {
            // Valid node wala case
            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

void storeInOrderTraversal(Node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    // LNR
    storeInOrderTraversal(root->left, in);
    in.push_back(root->data);
    storeInOrderTraversal(root->right, in);
}

void replaceUsingPostOrder(Node *root, vector<int> in, int &index)
{
    if (root == NULL)
    {
        return;
    }
    // LRN
    replaceUsingPostOrder(root->left, in, index);
    replaceUsingPostOrder(root->right, in, index);
    root->data = in[index];
    index++;
}

Node *convertBSTIntoMaxHeap(Node *root)
{
    // 1 Step: store inorder
    vector<int> inorder;
    storeInOrderTraversal(root, inorder);

    // replace the node values with the sorted inorder values,using the postOrder Traversal
    int index = 0;
    replaceUsingPostOrder(root, inorder, index);
    return root;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    // Test Case : 100 50 150 40 60 110 200 20 -1
    cout << "Printing the BST: " << endl;

    levelOrderTraversal(root);
    cout << endl;

    cout << "Converting Into Heap: " << endl;

    root = convertBSTIntoMaxHeap(root);
    cout << "Printing the heap: " << endl;
    levelOrderTraversal(root);
    return 0;
}