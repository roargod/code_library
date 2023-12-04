#define _CRT_SECURE_NO_WARNINGS
class Solution {
    vector<vector<int>>  ret;
    vector<int> path;
    bool check[7] = { false };
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return ret;
    }
    void dfs(vector<int>& nums)
    {
        //����
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }

        //������: 
        for (int i = 0; i < nums.size(); i++)
        {
            if (check[i] == false)
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums);
                //����->�ָ��ֳ�
                path.pop_back();
                check[i] = false;
            }
        }
    }
};