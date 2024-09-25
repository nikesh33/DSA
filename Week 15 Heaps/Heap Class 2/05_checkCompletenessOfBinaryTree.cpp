#include <iostream>
#include <queue>
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
    bool levelOrderTraversal(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        // Flag
        bool nullFound = false;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();

            if (front == NULL)
            {
                nullFound = true;
            }
            else
            {
                if (nullFound)
                    return false;

                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode *root) { return levelOrderTraversal(root); }
};

int main()
{
    // Creating a complete binary tree example
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution solution;

    // Check if the tree is complete
    if (solution.isCompleteTree(root))
        cout << "The tree is a complete binary tree." << endl;
    else
        cout << "The tree is not a complete binary tree." << endl;

    return 0;
}