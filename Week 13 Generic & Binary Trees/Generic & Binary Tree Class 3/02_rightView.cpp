#include <iostream>
#include <queue>
#include <vector>
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

Node *createTree()
{
    cout << "Enter the value for Node: ";
    int value;
    cin >> value;

    if (value == -1)
    {
        return NULL;
    }

    // create Node
    Node *root = new Node(value);
    cout << "Entering in left of: " << value << endl;
    root->left = createTree();
    cout << "Enter in right of: " << value << endl;
    root->right = createTree();
    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
}

// level order
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    cout << endl;
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

// Left View
void printRightView(Node *root, int level, vector<int> &rightView)
{
    if (root == NULL)
    {
        return;
    }

    if (level == rightView.size())
    {
        // iska matlab left view ki node milgayi hai store karlo
        rightView.push_back(root->data);
    }

    // bas ye right ko upar karne se right view ka ans aa jayega
    printRightView(root->right, level + 1, rightView);
    printRightView(root->left, level + 1, rightView);
}

int main()
{
    Node *root = createTree();
    levelOrderTraversal(root);

    // 10 20 40 -1 -1 50 30 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    // Ans => 10 20 40 30 110
    vector<int> rightView;
    printRightView(root, 0, rightView);
    cout << "Priting Left View: " << endl;

    for (int i = 0; i < rightView.size(); i++)
    {
        cout << rightView[i] << " ";
    }

    return 0;
}