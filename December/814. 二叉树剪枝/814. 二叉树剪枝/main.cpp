#define _CRT_SECURE_NO_WARNINGS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root);
    }
    TreeNode* dfs(TreeNode* root)
    {
        //³ö¿Ú
        if (root == nullptr) return nullptr;

        // TreeNode* rootLeft = dfs(root->left);
        // if(rootLeft == nullptr) root->left = nullptr;
        // TreeNode* rootRight = dfs(root->right);
        // if(rootRight == nullptr) root->right = nullptr;

        root->left = dfs(root->left);
        root->right = dfs(root->right);

        if (root->left == nullptr && root->right == nullptr && root->val == 0)
        {
            //delete root;
            root = nullptr;
        }
        return root;
    }
};