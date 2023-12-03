#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
    bool dfs(TreeNode* root)
    {
        if (root->left == nullptr) return root->val;
        if (root->right == nullptr) return root->val;
        //�����⣺�������������������������ж�val������ OR �� AND
        bool boolLeft = dfs(root->left);
        bool boolRight = dfs(root->right);

        if (root->val == 2)
        {
            return boolLeft | boolRight;
        }
        else
        {
            return boolLeft & boolRight;
        }

    }
};