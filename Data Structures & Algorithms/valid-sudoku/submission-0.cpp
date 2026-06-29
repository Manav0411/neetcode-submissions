class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (st.count(board[i][j]))
                        return false;
                    st.insert(board[i][j]);
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (st.count(board[j][i]))
                        return false;
                    st.insert(board[j][i]);
                }
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_set<char> st;
                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {
                        if (board[r][c] != '.') {
                            if (st.count(board[r][c]))
                                return false;
                            st.insert(board[r][c]);
                        }
                    }
                }
            }
        }

        return true;
    }
};