#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    // base case root null hai
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // its not the first node
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
    cout << "Enter data: " << endl;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter data: " << endl;
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

// preorder postorder

void preOrder(Node *root)
{
    // NLR
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//***IMPORTANT*// Inorder Traversal in BST is always sorted
void inorder(Node *root)
{
    // LNR
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node *root)
{
    // LRN
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *maxValue(Node *root)
{
    if (root == NULL)
    {
        cout << "No MIN Value Found" << endl;
        return NULL;
    }
    Node *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    // INPUT -> 50 30 20 25 40 60 70 80 55 -1
    // ANS || ->> Max Value: 80
    // 50
    // 30 60
    // 20 40 55 70
    // 25 80

    cout << "Preorder: ";
    preOrder(root);
    cout << endl
         << "Inorder: ";
    inorder(root);
    cout << endl
         << "Postorder: ";
    postorder(root);

    cout << endl;
    Node *maxNode = maxValue(root);

    // MAX
    if (maxNode == NULL)
    {
        cout << "No Max Value Found" << endl;
    }
    else
    {
        cout << "Max Value: " << maxNode->data << endl;
    }

    return 0;
}