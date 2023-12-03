#define _CRT_SECURE_NO_WARNINGS
/////////////////////////////////剪枝
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
    vector<string> ret;//记录结果
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";//记录路径
        dfs(root, path);
        return ret;
    }
    void dfs(TreeNode* root, string path)
    {

        //子问题
        //前序遍历
        //判断根节点
        if (root->left == nullptr && root->right == nullptr)
        {
            path += to_string(root->val);
            ret.push_back(path);
            return;
        }
        else
        {
            path += to_string(root->val) + "->";
        }
        if (root->left) dfs(root->left, path);
        if (root->right) dfs(root->right, path);
    }
};
/////////////////////////////////出口
class Solution {
    vector<string> ret;//记录结果
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";//记录路径
        dfs(root, path);
        return ret;
    }
    void dfs(TreeNode* root, string path)
    {
        //出口
        if (root == nullptr) return;

        //子问题
        //前序遍历
        //判断根节点
        if (root->left == nullptr && root->right == nullptr)
        {
            path += to_string(root->val);
            ret.push_back(path);
            return;
        }
        else
        {
            path += to_string(root->val) + "->";
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
};