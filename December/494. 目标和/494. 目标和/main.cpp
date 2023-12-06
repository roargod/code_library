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
        //����
        if (pos == nums.size())
        {
            if (path == target) count++;
            return;
        }

        // //�����⣺//path Ϊȫ�ֱ��� ��ʱ
        // for(int j = 0; j < 2; j++)
        // {
        //     path += nums[pos] * flag[j];
        //     dfs(nums, target, pos+1);
        //     //����
        //     path -= nums[pos] * flag[j];
        // }
        //�����⣺pathΪ�ֲ����� --- ����д��Ҳ��ʱ
        // for(int i = 0; i < 2; i++)
        // {
        //     path += nums[pos] * flag[i];
        //     dfs(nums, target, pos+1, path);
        //     //pathΪ�ֲ������ù��Ļ���1
        //     path -= nums[pos] * flag[i];
        // }
        dfs(nums, target, pos + 1, path + nums[pos]);
        dfs(nums, target, pos + 1, path - nums[pos]);
    }
};