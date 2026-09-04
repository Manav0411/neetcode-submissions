class Solution {
   public:
    bool issafe(int row, int col, vector<int>& cols, vector<int>& diag1, vector<int>& diag2,
                int n) {
        return !cols[col] && !diag1[row - col + n - 1] && !diag2[row + col];
    }
    void f(int row, int n, vector<vector<string>>& ans, vector<string>& board, vector<int>& cols,
           vector<int>& diag1, vector<int>& diag2) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (issafe(row, col, cols, diag1, diag2, n)) {
                board[row][col] = 'Q';
                cols[col] = true;
                diag1[row - col + n - 1] = true;
                diag2[row + col] = true;

                f(row + 1, n, ans, board, cols, diag1, diag2);

                board[row][col] = '.';
                cols[col] = false;
                diag1[row - col + n - 1] = false;
                diag2[row + col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> cols(n, 0);
        vector<int> diag1(2 * n, 0);
        vector<int> diag2(2 * n, 0);
        f(0, n, ans, board, cols, diag1, diag2);
        return ans;
    }
};
