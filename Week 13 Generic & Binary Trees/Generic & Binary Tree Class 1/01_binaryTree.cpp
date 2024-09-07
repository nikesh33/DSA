#include <iostream>
#include <queue>
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

// 1.19.0 Level Order Traversal (BFS)
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
int main()
{
    Node *root = createTree();
    // cout << root->data << endl;

    cout << "Level Order: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}