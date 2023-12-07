#define _CRT_SECURE_NO_WARNINGS
class Solution {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0, 0);
        return ret;
    }
    void dfs(vector<int>& candidates, int target, int pos, int sum)
    {
        //���ؽ��
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }
        //��֦ + ����
        if (sum > target || pos == candidates.size()) return;

        //�����⣺
        for (int i = 0; i * candidates[pos] + sum <= target; i++)
        {
            if (i > 0) path.push_back(candidates[pos]);
            dfs(candidates, target, pos + 1, sum + i * candidates[pos]);
        }
        //����
        for (int i = 1; i * candidates[pos] + sum <= target; i++)
        {
            path.pop_back();
        }
    }
};