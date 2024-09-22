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

Node *bstFromInorder(int inorder[], int s, int e)
{
    // Base case
    // agar start end se bada ho jaye to ruk jao
    if (s > e)
    {
        return NULL;
    }

    // 1 Case Solve Karna hai
    int mid = (s + e) / 2;
    // Element Nikal lo
    int element = inorder[mid];
    Node *root = new Node(element);

    // Baaki recursion
    root->left = bstFromInorder(inorder, s, mid - 1);
    root->right = bstFromInorder(inorder, mid + 1, e);

    return root;
}

// ******//
// Convert this BST into a sorted doubly Linked List
void convertBSTtoDLL(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }

    // RNL
    // R
    convertBSTtoDLL(root->right, head);

    // N
    // attaching next pointer of current node to head of LL
    root->right = head;
    // attaching prev pointer of head of LL to current Node
    if (head != NULL)
        head->left = root;
    // head update
    head = root;

    // L
    convertBSTtoDLL(root->left, head);
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    cout << "Printing the entire list: " << endl;
    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->right;
    }
    cout << endl;
}

int main()
{
    int inorder[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int start = 0;
    int end = size - 1;
    Node *root = bstFromInorder(inorder, start, end);
    levelOrderTraversal(root);

    Node *head = NULL;
    convertBSTtoDLL(root, head);
    printLinkedList(head);

    return 0;
}