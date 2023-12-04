#define _CRT_SECURE_NO_WARNINGS
class Solution {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // ret.push_back()?;
        dfs(nums, 0);
        return ret;
    }
    void dfs(vector<int>& nums, int pos)
    {
        // if(pos == nums.size())
        // {
        //     ret.push_back(path);
        //     return;
        // }

        //子问题：
        //选择pos后的元素
        ret.push_back(path);

        for (int i = pos; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            //回溯
            path.pop_back();
        }
    }
};

class Solution {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // ret.push_back()?;
        dfs(nums, 0);
        return ret;
    }
    void dfs(vector<int>& nums, int pos)
    {
        //子问题：
        //选择pos后的元素
        ret.push_back(path);

        for (int i = pos; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            //回溯
            path.pop_back();
        }
    }
};