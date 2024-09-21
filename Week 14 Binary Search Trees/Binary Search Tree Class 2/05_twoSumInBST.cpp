#include <iostream>
#include <vector>
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
    void storeInorder(TreeNode *root, vector<int> &inorder)
    {
        // base case
        if (root == NULL)
        {
            return;
        }
        // LNR
        // L
        storeInorder(root->left, inorder);
        // N
        inorder.push_back(root->val);
        // R
        storeInorder(root->right, inorder);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        storeInorder(root, inorder);

        // find Target using 2 pointer approach
        int start = 0;
        int end = inorder.size() - 1;

        while (start < end)
        {
            int sum = inorder[start] + inorder[end];
            if (sum == k)
            {
                return true;
            }
            else if (sum > k)
            {
                end--;
            }
            else if (sum < k)
            {
                start++;
            }
        }
        return false;
    }
};

int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution solution;
    int target = 9;

    if (solution.findTarget(root, target))
    {
        std::cout << "Target " << target << " found in the tree." << std::endl;
    }
    else
    {
        std::cout << "Target " << target << " not found in the tree." << std::endl;
    }

    // Cleanup (optional)
    // (You may want to implement a proper tree deletion function to avoid memory leaks)

    return 0;
}