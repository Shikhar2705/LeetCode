#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9,vector<int>(9,0));
        vector<vector<int>> cols(9,vector<int>(9,0));
        int blocks[3][3][9] = {0};

        for (int r = 0; r < 9; r++) {
          for (int c = 0; c < 9; c++) {
            if (board[r][c] != '.') {
              int number = board[r][c] - '1';
              if (rows[r][number]++) return false;
              if (cols[c][number]++) return false;
              if (blocks[r/3][c/3][number]++) return false;
            }
          }
        }

        return true;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;

    if (s.isValidSudoku(board))
    {
        cout << "Valid Sudoku" << endl;
    }
    else
    {
        cout << "Invalid Sudoku" << endl;
    }
    return 0;
}