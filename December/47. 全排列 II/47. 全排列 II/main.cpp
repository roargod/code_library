#define _CRT_SECURE_NO_WARNINGS
class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    bool check[9] = { false };
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ret;
    }
    void dfs(vector<int>& nums, int pos)
    {
        //出口
        if (nums.size() == pos)
        {
            ret.push_back(path);
            return;
        }

        //子问题：
        //遍历每个元素，选择
        for (int i = 0; i < nums.size(); i++)
        {
            //只关心不合法的情况
            if (check[i] == true || (i > 0 && nums[i] == nums[i - 1] && check[i - 1] == false))
                continue;
            //只关心合法的情况
            // if(check[i] == false && (i == 0 || nums[i] != nums[i-1] || check[i-1] == true))
            if (check[i] == false)
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums, pos + 1);
                //回溯
                check[i] = false;
                path.pop_back();
            }
        }
    }
};