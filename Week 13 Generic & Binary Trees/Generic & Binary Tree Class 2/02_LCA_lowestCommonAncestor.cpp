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
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == p->val)
        {
            return p;
        }
        if (root->val == q->val)
        {
            return q;
        }

        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);
        if (leftAns == NULL && rightAns == NULL)
        {
            return NULL;
        }
        else if (leftAns != NULL && rightAns == NULL)
        {
            return leftAns;
        }
        else if (leftAns == NULL && rightAns != NULL)
        {
            return rightAns;
        }
        else
        {
            return root;
        }
    }
};

int main()
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Set the nodes p and q
    TreeNode *p = root->left;               // Node with value 5
    TreeNode *q = root->left->right->right; // Node with value 4

    // Create an instance of Solution
    Solution sol;

    // Find LCA
    TreeNode *lca = sol.lowestCommonAncestor(root, p, q);

    if (lca != nullptr)
    {
        cout << "The lowest common ancestor of " << p->val << " and " << q->val << " is " << lca->val << "." << endl;
    }
    else
    {
        cout << "No common ancestor found." << endl;
    }

    return 0;
}