#define _CRT_SECURE_NO_WARNINGS
class Solution {
    vector<vector<string>> ret;
    vector<string> path;
    bool checkCol[10] = { false };
    bool checkDig1[20] = { false };
    bool checkDig2[20] = { false };

public:
    vector<vector<string>> solveNQueens(int n) {
        path.resize(n);
        for (int i = 0; i < n; i++)
            path[i].append(n, '.');
        dfs(n, 0);
        return ret;
    }
    void dfs(int n, int row)
    {
        //����
        if (row == n)
        {
            ret.push_back(path);
            return;
        }

        //�����⣺
        for (int col = 0; col < n; col++)
        {
            if (!checkCol[col] && !checkDig1[row - col + n] && !checkDig2[row + col])
            {
                path[row][col] = 'Q';
                //���
                checkCol[col] = checkDig1[row - col + n] = checkDig2[row + col] = true;
                dfs(n, row + 1);
                //����
                path[row][col] = '.';
                checkCol[col] = checkDig1[row - col + n] = checkDig2[row + col] = false;
            }
        }
    }
};