#define _CRT_SECURE_NO_WARNINGS
class Solution {
    vector<string> ret;
    string path;
    string hash[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ret;
        dfs(digits, 0);
        return ret;
    }
    void dfs(string& digits, int pos)
    {
        //出口
        if (pos == digits.size())
        {
            ret.push_back(path);
            return;
        }

        //子问题：
        for (int i = 0; i < hash[digits[pos] - '0'].size(); i++)
        {
            path += hash[digits[pos] - '0'][i];
            dfs(digits, pos + 1);
            //回溯
            path.pop_back();
        }
    }
};