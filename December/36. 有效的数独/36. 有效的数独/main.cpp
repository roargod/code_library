#define _CRT_SECURE_NO_WARNINGS
class Solution {
    bool col[9][10];
    bool row[9][10];
    bool grid[3][3][10];
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if (row[i][num] == true || col[j][num] == true || grid[i / 3][j / 3][num] == true)
                        return false;
                    else
                        row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
                }
            }
        return true;
    }
};