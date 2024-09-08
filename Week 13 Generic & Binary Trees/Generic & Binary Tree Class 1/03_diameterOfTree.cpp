#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int height(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            return 0;
        }
        // baaki ka case
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int height = max(leftHeight, rightHeight) + 1;
        return height;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            return 0;
        }

        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = height(root->left) + height(root->right) + 1;
        int diameter = max(option1, max(option2, option3));
        return diameter;
    }
};

int main()
{

    return 0;
}