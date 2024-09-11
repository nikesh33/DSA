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
    void solve(TreeNode *root, int targetSum, vector<vector<int>> &ans,
               vector<int> temp, int sum)
    {
        // base case
        if (root == NULL)
        {
            return;
        }
        // 1 case solve
        sum += root->val;
        temp.push_back(root->val);

        // extra case
        if (root->left == NULL && root->right == NULL)
        {
            // varify
            if (sum == targetSum)
            {
                // store temp path in final ans array
                ans.push_back(temp);
            }
            else
            {
                return;
            }
        }
        // baki ka case
        solve(root->left, targetSum, ans, temp, sum);
        solve(root->right, targetSum, ans, temp, sum);
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, targetSum, ans, temp, sum);
        return ans;
    }
};

int main()
{
    // Create a sample binary tree:
    //        5
    //       / \
    //      4   8
    //     /   / \
    //    11  13  4
    //   /  \     / \
    //  7    2   5   1

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    // Define target sum
    int targetSum = 22;

    // Create an instance of Solution and find all root-to-leaf paths with the sum
    Solution solution;
    vector<vector<int>> result = solution.pathSum(root, targetSum);

    // Print the result
    cout << "Paths with sum " << targetSum << ":" << endl;
    for (const auto &path : result)
    {
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}