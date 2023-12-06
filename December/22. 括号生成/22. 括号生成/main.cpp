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
        //��֦
        if (rightCount > leftCount || leftCount > n) return;
        //����
        if (pos == n * 2)
        {
            ret.push_back(path);
            return;
        }
        //�����⣺
        for (int i = 0; i < 2; i++)
        {
            if (choice[i] == '(') leftCount++;
            else rightCount++;
            path += choice[i];
            dfs(n, pos + 1);
            //����
            if (choice[i] == '(') leftCount--;
            else rightCount--;
            path.pop_back();
        }
    }
};