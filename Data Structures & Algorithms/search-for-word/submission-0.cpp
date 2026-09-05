class Solution {
   public:
    bool f(int row, int col, vector<vector<char>>& board, string word, int idx,
           vector<vector<bool>>& visited) {
        if (idx == word.length()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            visited[row][col] || board[row][col] != word[idx]) {
            return false;
        }
        visited[row][col] = true;

        bool found = f(row + 1, col, board, word, idx + 1, visited) ||
                     f(row, col + 1, board, word, idx + 1, visited) ||
                     f(row - 1, col, board, word, idx + 1, visited) ||
                     f(row, col - 1, board, word, idx + 1, visited);

        visited[row][col] = false;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (f(row, col, board, word, 0, visited)) return true;
            }
        }

        return false;
    }
};