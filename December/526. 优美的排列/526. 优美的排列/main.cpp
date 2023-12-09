#define _CRT_SECURE_NO_WARNINGS
class Solution {
    int ret;
    bool boolCheck[16] = { false };
public:
    int countArrangement(int n) {
        dfs(n, 0);
        return ret;
    }
    void dfs(int n, int pos)
    {
        //出口
        if (pos == n)
        {
            ret++;
            return;
        }
        //子问题：
        for (int i = 1; i <= n; i++)
        {
            //查看这个数，前几层有没有使用过
            if (boolCheck[i] == false && ((pos + 1) % i == 0 || i % (pos + 1) == 0))
            {
                boolCheck[i] = true;
                dfs(n, pos + 1);
                boolCheck[i] = false;
            }
        }
    }
};