class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // check column (above)
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // check upper-left diagonal
        int i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i--; j--;
        }

        // check upper-right diagonal
        i = row; j = col;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') return false;
            i--; j++;
        }

        return true;
    }

    void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';             // place
                nQueens(board, row + 1, n, ans);   // explore
                board[row][col] = '.';             // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        nQueens(board, 0, n, ans);
        return ans;
    }
};