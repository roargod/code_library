#define _CRT_SECURE_NO_WARNINGS
class Solution {
    int ret = 0;
    int path = 0;
public:
    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }
    void dfs(vector<int>& nums, int pos)
    {
        //子问题：
        //保存结果
        ret += path;
        //从pos位置向后选择元素
        for (int i = pos; i < nums.size(); i++)
        {
            path ^= nums[i];
            dfs(nums, i + 1);
            //回溯
            path ^= nums[i];
        }
    }
};