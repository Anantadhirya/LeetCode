class Solution {
public:
    void solve(vector<vector<char>> &board, vector<vector<char>> &ans, bool &solved, int i = 0, int j = 0) {
        if(solved) return;
        if(i == 9) {
            ans = board;
            solved = 1;
            return;
        }
        int ii = (j == 8 ? i+1 : i);
        int jj = (j == 8 ? 0 : j+1);
        if(board[i][j] != '.') {
            solve(board, ans, solved, ii, jj);
            return;
        }
        bitset<9> b;
        for(int k = 0; k < 9; k++) {
            if(board[i][k] != '.') b[board[i][k] - '1'] = 1;
            if(board[k][j] != '.') b[board[k][j] - '1'] = 1;
        }
        for(int ki = 0, si = i/3*3, sj = j/3*3; ki < 3; ki++) {
            for(int kj = 0; kj < 3; kj++) {
                if(board[si+ki][sj+kj] != '.') b[board[si+ki][sj+kj] - '1'] = 1;
            }
        }
        for(int k = 0; k < 9; k++) {
            if(b[k]) continue;
            board[i][j] = '1' + k;
            solve(board, ans, solved, ii, jj);
            board[i][j] = '.';
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> ans;
        bool solved = 0;
        solve(board, ans, solved);
        board = ans;
    }
};