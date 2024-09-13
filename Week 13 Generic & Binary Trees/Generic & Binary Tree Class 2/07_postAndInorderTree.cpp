#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Node Creation
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

// It returns root node of the created tree
Node *createTree()
{
    cout << "Enter the Value for Node: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // 1 Create Node
    Node *root = new Node(data);
    // left
    root->left = createTree();
    // right
    root->right = createTree();

    return root;
}

// PreOrder Traversal Logic
void preOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // NLR
    // N
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

// InOrder Traversal Logic
void inorderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    //   LNR
    // L
    inorderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inorderTraversal(root->right);
}

// Postorder Traversal
void postorderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // LRN
    // L
    postorderTraversal(root->left);
    // R
    postorderTraversal(root->right);
    // N
    cout << root->data << " ";
}

// Level Order Traversal
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    // Traversal
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

// MAX DEPTH
int maxDepth(Node *root)
{
    // IMP GALTI
    if (root == NULL)
    {
        return 0;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int count = 1;

    // Traversal
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                count++;
                q.push(NULL);
            }
        }
        else
        {
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
    return count;
}

// Height
int height(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int height = max(leftHeight, rightHeight) + 1;
    return height;
}

// Diameter
int diameterOfBinaryTree(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    int option1 = diameterOfBinaryTree(root->left);
    int option2 = diameterOfBinaryTree(root->right);
    int option3 = height(root->left) + height(root->right);
    int diameter = max(option1, max(option2, option3));
    return diameter;
}

int searchInorder(int inorder[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (inorder[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// Creating MAP
void createMapping(int inorder[], int size, map<int, int> &valueToIndexMap)
{
    for (int i = 0; i < size; i++)
    {
        int element = inorder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

// int &preIndex  yaha pe faste hai by ref pass karna hota hai
Node *constructTreeFromPreAndInorderTraversal(map<int, int> &valueToIndexMap, int preOrder[], int inOrder[], int &preIndex, int inOrderStart, int inOrderEnd, int size)
{
    // base case
    if (preIndex >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // 1 case
    int element = preOrder[preIndex];
    preIndex++;
    Node *root = new Node(element);
    // element search karna padega inorder me
    // in O of n
    // int position = searchInorder(inOrder, size, element);
    // O of 1 me
    int position = valueToIndexMap[element];

    // baki ka recursion
    root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, inOrderStart, position - 1, size);
    root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, position + 1, inOrderEnd, size);

    return root;
}

Node *constructTreeFromPostAndInorderTraversal(map<int, int> &valueToIndexMap, int postorder[], int inOrder[], int &postorderIndex, int inOrderStart, int inOrderEnd, int size)
{
    // base case
    if (postorderIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // 1 case
    int element = postorder[postorderIndex];
    postorderIndex--;
    Node *root = new Node(element);
    // search karo inorder me
    int position = valueToIndexMap[element];
    // baki ka recursion
    // right ki call pehle lagegi LRN pehele right wala part aata hai islye pehle right wala
    root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inOrder, postorderIndex, position + 1, inOrderEnd, size);
    root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inOrder, postorderIndex, inOrderStart, position - 1, size);
    return root;
}

int main()
{
    // int inorder[] = {10, 8, 6, 2, 4, 12};
    // int preOrder[] = {2, 8, 10, 6, 4, 12};
    // int size = 6;
    // int preOrderIndex = 0;
    // int inorderStart = 0;
    // int inorderEnd = 5;
    // map<int, int> valueToIndexMap;
    // createMapping(inorder, size, valueToIndexMap);

    // Node *root = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inorder, preOrderIndex, inorderStart, inorderEnd, size);

    int inorder[] = {8, 14, 6, 2, 10, 4};
    int postorder[] = {8, 6, 14, 4, 10, 2};
    int size = 6;
    int postorderIndex = size - 1;
    int inorderStart = 0;
    int inorderEnd = size - 1;
    map<int, int> valueToIndexMap;
    createMapping(inorder, size, valueToIndexMap);
    Node *root = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inorder, postorderIndex, inorderStart, inorderEnd, size);
    cout << "Printing The Entire Tree: " << endl;
    levelOrderTraversal(root);

    return 0;
}