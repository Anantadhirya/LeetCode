class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(int i, int j, int &n, int &m, vector<vector<char>> &board) {
        if(board[i][j] != 'O') return;
        board[i][j] = '.';
        for(int d = 0, ii, jj; d < 4; d++) {
            ii = i + dx[d];
            jj = j + dy[d];
            if(0 <= ii && ii < n && 0 <= jj && jj < m) {
                dfs(ii, jj, n, m, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            dfs(i, 0, n, m, board);
            dfs(i, m-1, n, m, board);
        }
        for(int j = 0; j < m; j++) {
            dfs(0, j, n, m, board);
            dfs(n-1, j, n, m, board);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                board[i][j] = (board[i][j] == '.' ? 'O' : 'X');
            }
        }
    }
};