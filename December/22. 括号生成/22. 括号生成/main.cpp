#define _CRT_SECURE_NO_WARNINGS
class Solution {
    vector<string> ret;
    string choice = "()";
    int leftCount = 0;
    int rightCount = 0;
    string path = "";
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, 0);
        return ret;
    }
    void dfs(int n, int pos)
    {
        //剪枝
        if (rightCount > leftCount || leftCount > n) return;
        //出口
        if (pos == n * 2)
        {
            ret.push_back(path);
            return;
        }
        //子问题：
        for (int i = 0; i < 2; i++)
        {
            if (choice[i] == '(') leftCount++;
            else rightCount++;
            path += choice[i];
            dfs(n, pos + 1);
            //回溯
            if (choice[i] == '(') leftCount--;
            else rightCount--;
            path.pop_back();
        }
    }
};