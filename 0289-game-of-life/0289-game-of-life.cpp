class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = board.size();
        int m = board[0].size();
        int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
        int tmp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tmp = 0;
                for(int d = 0, ii, jj; d < 8; d++) {
                    ii = i + dx[d];
                    jj = j + dy[d];
                    if(0 <= ii && ii < n && 0 <= jj && jj < m) {
                        tmp += (board[ii][jj] > 0);
                    }
                }
                board[i][j] = (tmp+1) * (board[i][j] ? 1 : -1);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] > 0) {
                    board[i][j] = board[i][j] - 1;
                    board[i][j] = (2 <= board[i][j] && board[i][j] <= 3);
                } else {
                    board[i][j] = -board[i][j] - 1;
                    board[i][j] = (board[i][j] == 3);
                }
            }
        }
    }
};