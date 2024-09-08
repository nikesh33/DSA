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
    int maxDepth(TreeNode *root)
    {
        //********* Solution 1: using level order traversal ********//
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int count = 1;

        // Asli traversal start karte hai
        if (root == NULL)
        {
            return 0;
        }
        // while (!q.empty())
        // while (q.size() > 1)
        while (!q.empty())
        {
            TreeNode *front = q.front();
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
                // Valid node wala case

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

    //********* Solution 2: using recursion ********//
    // {
    //     // base case
    //     if (root == NULL)
    //     {
    //         return 0;
    //     }
    //     // baaki ka case
    //     int leftHeight = maxDepth(root->left);
    //     int rightHeight = maxDepth(root->right);
    //     int height = max(leftHeight, rightHeight) + 1;
    //     return height;
    // }
};

int main()
{
    // Create a simple binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Create an instance of Solution and calculate max depth
    Solution sol;
    int depth = sol.maxDepth(root);

    // Print the result
    cout << "The maximum depth of the binary tree is: " << depth << endl;

    // Clean up the memory
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}