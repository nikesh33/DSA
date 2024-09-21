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
    int kthSmallest(TreeNode *root, int &k)
    {
        // Base Case
        if (root == NULL)
        {
            return -1;
        }
        // LNR
        // L
        int leftAns = kthSmallest(root->left, k);
        if (leftAns != -1)
        {
            return leftAns;
        }
        // N
        k--;
        if (k == 0)
        {
            return root->val;
        }
        // R
        // WHY NOT IF Condition? -> this is because left and node pe ans nahi mila we have to return  somthing whatever right gives
        int rightAns = kthSmallest(root->right, k);
        return rightAns;
    }
};

int main()
{
    // Create a binary search tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution solution;

    int k = 3;
    int result = solution.kthSmallest(root, k);
    cout << "The " << 3 << "rd smallest element in the BST is: " << result << endl;

    return 0;
}
