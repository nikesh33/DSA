#include <iostream>
#include <queue>
#include <map>
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

// void preOrder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     cout << root->data;
//     preOrder(root->left);
//     preOrder(root->right);
// }

// void inOrder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     inOrder(root->left);
//     cout << root->data;
//     inOrder(root->right);
// }

// void postOrder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     postOrder(root->left);
//     postOrder(root->right);
//     cout << root->data;
// }

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

// // Left View
// void printRightView(Node *root, int level, vector<int> &rightView)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     if (level == rightView.size())
//     {
//         // iska matlab left view ki node milgayi hai store karlo
//         rightView.push_back(root->data);
//     }

//     // bas ye right ko upar karne se right view ka ans aa jayega
//     printRightView(root->right, level + 1, rightView);
//     printRightView(root->left, level + 1, rightView);
// }

// void printTopView(Node *root)
// {
//     // Map crreate
//     map<int, int> hdToNodemap;
//     queue<pair<Node *, int>> q;
//     q.push(make_pair(root, 0));

//     while (!q.empty())
//     {
//         pair<Node *, int> temp = q.front();
//         q.pop();

//         Node *frontNode = temp.first;
//         int hd = temp.second;

//         // ******** BAS YAHI CHANGE KARNA THA
//         // if there is no entry for hd in map, then create a new entry
//         // if (hdToNodemap.find(hd) == hdToNodemap.end()){
//         // hdToNodemap[hd] = frontNode->data;
//         // }

//         // Without condition agar map me ans stored bhi hai tab bhi store karoge to end ka ans aa jayega ******// ||<<<<---
//         hdToNodemap[hd] = frontNode->data;
//         // child ko dekhna hai
//         if (frontNode->left != NULL)
//         {
//             q.push(make_pair(frontNode->left, hd - 1));
//         }
//         if (frontNode->right != NULL)
//         {
//             q.push(make_pair(frontNode->right, hd + 1));
//         }
//     }
//     cout << "Printing Top View: " << endl;
//     for (auto i : hdToNodemap)
//     {
//         cout << i.second << " ";
//     }
// }

// Left View Print karne ka logic
void printLeftBoundary(Node *root)
{
    //  base case
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    cout << root->data << " ";
    if (root->left != NULL)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // matalab leaf node hai
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }
    // preorder
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node *root)
{
    //  base case
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    if (root->right != NULL)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }
    cout << root->data << " ";
}

void boundaryTraversal(Node *root)
{
    // if (root == NULL)
    // {
    //     return;
    // }
    // printLeftBoundary(root);
    // printLeafBoundary(root);
    // if (root->right != NULL)
    // {
    //     printRightBoundary(root->right);
    // }
    // else
    // {
    //     printRightBoundary(root->left);
    // }

    // can also be done printing root first
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printLeftBoundary(root->left);
    // single node wale case me do bar print ho sakta hai is liye leaf node k liye 2 condition lagya left then right
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
    printRightBoundary(root->right);
}

int main()
{
    Node *root = createTree();
    levelOrderTraversal(root);
    boundaryTraversal(root);
    // 10 20 40 -1 -1 50 30 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    // ANS -> 10 20 40 110 111 80 112 113 90 60 30

    return 0;
}