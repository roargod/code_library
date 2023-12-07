#define _CRT_SECURE_NO_WARNINGS
class Solution {
    vector<string> ret;
    string path;
public:
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ret;
    }
    void dfs(string& s, int pos)
    {
        //出口
        if (pos == s.size())
        {
            ret.push_back(path);
            return;
        }
        //子问题：
        char ch = s[pos];
        //不变
        path.push_back(ch);
        dfs(s, pos + 1);
        //回溯
        path.pop_back();
        //变
        if (ch < '0' || ch > '9')
        {
            path.push_back(change(ch));
            dfs(s, pos + 1);
            //回溯
            path.pop_back();
        }
    }
    char change(char ch)
    {
        if (ch >= 'a' && ch <= 'z') return toupper(ch);
        else return tolower(ch);
    }
};