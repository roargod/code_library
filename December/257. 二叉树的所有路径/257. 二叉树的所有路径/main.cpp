#define _CRT_SECURE_NO_WARNINGS
/////////////////////////////////��֦
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
    vector<string> ret;//��¼���
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";//��¼·��
        dfs(root, path);
        return ret;
    }
    void dfs(TreeNode* root, string path)
    {

        //������
        //ǰ�����
        //�жϸ��ڵ�
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
/////////////////////////////////����
class Solution {
    vector<string> ret;//��¼���
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";//��¼·��
        dfs(root, path);
        return ret;
    }
    void dfs(TreeNode* root, string path)
    {
        //����
        if (root == nullptr) return;

        //������
        //ǰ�����
        //�жϸ��ڵ�
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