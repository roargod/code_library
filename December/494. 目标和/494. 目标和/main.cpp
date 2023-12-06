#define _CRT_SECURE_NO_WARNINGS
class Solution {
    // int path = 0;
    int count = 0;
    int flag[2] = { -1, 1 };
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums, target, 0, 0);
        return count;
    }
    void dfs(vector<int>& nums, int target, int pos, int path)
    {
        //出口
        if (pos == nums.size())
        {
            if (path == target) count++;
            return;
        }

        // //子问题：//path 为全局变量 超时
        // for(int j = 0; j < 2; j++)
        // {
        //     path += nums[pos] * flag[j];
        //     dfs(nums, target, pos+1);
        //     //回溯
        //     path -= nums[pos] * flag[j];
        // }
        //子问题：path为局部变量 --- 这种写法也超时
        // for(int i = 0; i < 2; i++)
        // {
        //     path += nums[pos] * flag[i];
        //     dfs(nums, target, pos+1, path);
        //     //path为局部，不用关心回溯1
        //     path -= nums[pos] * flag[i];
        // }
        dfs(nums, target, pos + 1, path + nums[pos]);
        dfs(nums, target, pos + 1, path - nums[pos]);
    }
};