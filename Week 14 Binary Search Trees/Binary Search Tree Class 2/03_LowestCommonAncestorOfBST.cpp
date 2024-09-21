#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // Base Case
        if (root == NULL)
        {
            return NULL;
        }

        // Case 1: p and q both comes in left subtree of root node
        if (p->val < root->val && q->val < root->val)
        {
            TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }

        // Case 2: p and q both comes in right subtree of root node
        else if (p->val > root->val && q->val > root->val)
        {
            TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }

        // Case 3: p is in left subtree of root node && q is on right subtree of root node
        else if (p->val < root->val && q->val > root->val)
        {
            return root;
        }

        // Case 4: q is in left subtree of root node && p is on right subtree of root node
        else
        {
            return root;
        }
        return root;
    }
};

// Function to build a binary search tree CHATGPT
TreeNode *buildTree()
{
    // Create the nodes for the binary tree
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    return root;
}

int main()
{
    // Build the binary search tree
    TreeNode *root = buildTree();

    // Create Solution object
    Solution solution;

    // Define the nodes p and q
    TreeNode *p = root->left;  // Node with value 2
    TreeNode *q = root->right; // Node with value 8

    // Find the lowest common ancestor
    TreeNode *lca = solution.lowestCommonAncestor(root, p, q);

    // Output the value of the lowest common ancestor
    if (lca != NULL)
    {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    }
    else
    {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}