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
    long prevNum = LONG_MIN;//Êý¾Ý·¶Î§ -2^31 <= Node.val <= 2^31 - 1

public:
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
    //±©Á¦
    // bool dfs(TreeNode* root)
    // {
    //     //¿ÕÊ÷Ò²ÊÇ¶þ²æËÑË÷Ê÷
    //     if(root == nullptr) return true;

    //     bool boolLeft = dfs(root->left);

    //     bool flag = false;
    //     if(prevNum < root->val) flag = true;
    //     prevNum = root->val;

    //     bool boolRight = dfs(root->right);

    //     return flag && boolLeft && boolRight;
    // }
    //¼ôÖ¦
    bool dfs(TreeNode* root)
    {
        //¿ÕÊ÷Ò²ÊÇ¶þ²æËÑË÷Ê÷
        if (root == nullptr) return true;

        bool boolLeft = dfs(root->left);
        //¼ôÖ¦
        if (boolLeft == false) return false;

        bool flag = false;
        if (prevNum < root->val) flag = true;
        prevNum = root->val;
        //¼ôÖ¦
        if (flag == false) return false;

        bool boolRight = dfs(root->right);

        return flag && boolLeft && boolRight;
    }
};
