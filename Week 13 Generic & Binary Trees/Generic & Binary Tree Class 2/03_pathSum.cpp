#include <iostream>
using namespace std;
//  Definition for a binary tree node.
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
    bool solve(TreeNode *root, int targetSum, int sum)
    {
        // base case
        if (root == NULL)
        {
            return false;
        }
        sum += root->val;
        if (root->left == NULL && root->right == NULL)
        {
            // I AM Currently standing on a leaf node

            // varify
            if (sum == targetSum)
            {
                return true;
            }
            else
                return false;
        }
        bool leftAns = solve(root->left, targetSum, sum);
        bool rightAns = solve(root->right, targetSum, sum);

        return leftAns || rightAns;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};

int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    Solution solution;
    bool result = solution.hasPathSum(root, targetSum);

    if (result)
    {
        cout << "There is a path with the sum " << targetSum << "." << endl;
    }
    else
    {
        cout << "There is no path with the sum " << targetSum << "." << endl;
    }

    // Free the allocated memory
    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
