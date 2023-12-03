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
    int count = 0, ret = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        dfs(root);
        return ret;
    }
    void dfs(TreeNode* root)
    {
        //����
        //�Ż�����֦
        if (root == nullptr || count == 0) return;
        //������
        //����������ж�count == 0, ����ret
        dfs(root->left);
        count--;
        if (count == 0)
        {
            ret = root->val;
            //��֦
            return;
        }
        dfs(root->right);
    }
};