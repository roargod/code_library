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
        //����
        if (pos == s.size())
        {
            ret.push_back(path);
            return;
        }
        //�����⣺
        char ch = s[pos];
        //����
        path.push_back(ch);
        dfs(s, pos + 1);
        //����
        path.pop_back();
        //��
        if (ch < '0' || ch > '9')
        {
            path.push_back(change(ch));
            dfs(s, pos + 1);
            //����
            path.pop_back();
        }
    }
    char change(char ch)
    {
        if (ch >= 'a' && ch <= 'z') return toupper(ch);
        else return tolower(ch);
    }
};