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

// void preOrder(Node *root)
// {
//     // NLR
//     if (root == NULL)
//     {
//         return;
//     }
//     cout << root->data << " ";
//     preOrder(root->left);
//     preOrder(root->right);
// }

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
// void postorder(Node *root)
// {
//     // LRN
//     if (root == NULL)
//     {
//         return;
//     }
//     postorder(root->left);
//     postorder(root->right);
//     cout << root->data << " ";
// }

Node *minValue(Node *root)
{
    if (root == NULL)
    {
        cout << "No MIN Value Found" << endl;
        return NULL;
    }
    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
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

bool searchInBST(Node *root, int target)
{
    // Base Case
    if (root == NULL)
    {
        return false;
    }

    // 1 Case Mujhe Solve Karna hai
    if (root->data == target)
    {
        return true;
    }

    // Baki ka Case main solve karunga
    // Left ya right
    bool leftAns = false;
    bool rightAns = false;
    if (target > root->data)
    {
        rightAns = searchInBST(root->right, target);
    }
    else
    {
        leftAns = searchInBST(root->left, target);
    }

    // agar left me ans hai to bhi true hoga right me mila hai to bhi true rahega
    return leftAns || rightAns;
}

Node *deleteFromBST(Node *root, int target)
{
    // Target ko dhundo
    // Target KO delete karo

    // BASE CASE
    if (root == NULL)
    {
        return NULL;
    }

    // 1 CASE
    if (root->data == target)
    {
        // ab delete karenge
        // 4 CASES

        if (root->left == NULL && root->right == NULL)
        {
            // CASE 1 -> Leaf Node
            delete root;
            return NULL;
        }

        else if (root->left != NULL && root->right == NULL)
        {
            // CASE 2 -> left Non NULL and right NULL hai
            Node *childSubTree = root->left;
            delete root;
            return childSubTree;
        }

        else if (root->left == NULL && root->right != NULL)
        {
            // CASE 3 -> Right NON NULL and Left NULL hai
            Node *childSubTree = root->right;
            delete root;
            return childSubTree;
        }

        else
        {
            // CASE 4 -> Left NON NULL && Right NON NULL
            // a -> left subtree ki max value laao
            Node *maxi = maxValue(root->left);
            // Replacement
            root->data = maxi->data;
            // delete actual maxi wali node
            root->left = deleteFromBST(root->left, maxi->data);
        }
    }
    else if (root->data > target) // agar root ka data bada hai target se to target left side hoga
    {
        // Left me chalo
        root->left = deleteFromBST(root->left, target);
    }

    else
    { // agar root chota hai target se to ans right me exist karta hai
      // Right me chalo
        root->right = deleteFromBST(root->right, target);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    // INPUT ->50 30 60 25 40 70 80 55 -1
    // ANS || ->> Max Value: 80
    // 50
    // 30 60
    // 20 40 55 70
    // 25 80

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    int target;
    cout << "Enter the Value of target for deletion: " << endl;
    cin >> target;

    while (target != -1)
    {
        root = deleteFromBST(root, target);
        cout << "Printing Level Order Traversal: " << endl;
        levelOrderTraversal(root);
        cout << "Enter the Value of target for deletion: " << endl;
        cin >> target;
    }

    return 0;
}