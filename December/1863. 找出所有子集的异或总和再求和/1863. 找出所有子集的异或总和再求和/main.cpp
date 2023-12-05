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
        //�����⣺
        //������
        ret += path;
        //��posλ�����ѡ��Ԫ��
        for (int i = pos; i < nums.size(); i++)
        {
            path ^= nums[i];
            dfs(nums, i + 1);
            //����
            path ^= nums[i];
        }
    }
};