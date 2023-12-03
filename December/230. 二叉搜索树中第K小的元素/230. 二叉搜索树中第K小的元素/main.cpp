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
        //出口
        //优化：剪枝
        if (root == nullptr || count == 0) return;
        //子问题
        //中序变量，判断count == 0, 返回ret
        dfs(root->left);
        count--;
        if (count == 0)
        {
            ret = root->val;
            //剪枝
            return;
        }
        dfs(root->right);
    }
};