#define _CRT_SECURE_NO_WARNINGS
class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    int count = 0;
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ret;
    }
    void dfs(int n, int k, int pos)
    {
        //����
        if (count == k)
        {
            ret.push_back(path);
            return;
        }

        //�����⣺
        for (int i = pos; i <= n; i++)
        {
            path.push_back(i);
            count++;
            dfs(n, k, i + 1);
            //����
            path.pop_back();
            count--;
        }
    }
};