class Solution {
public:
    const int MOD = 1e9 + 7;
    pair<int, int> join(pair<int, int> &a, pair<int, int> &b) {
        if(a.first > b.first) return a;
        if(a.first < b.first) return b;
        return {a.first, (a.second + b.second) % MOD};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        dp[n-1][n-1] = {0, 1};
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(dp[i][j].first == -1) continue;
                if('1' <= board[i][j] && board[i][j] <= '9') dp[i][j].first += (board[i][j]-'0');
                if(i-1 >= 0 && board[i-1][j] != 'X') dp[i-1][j] = join(dp[i-1][j], dp[i][j]);
                if(j-1 >= 0 && board[i][j-1] != 'X') dp[i][j-1] = join(dp[i][j-1], dp[i][j]);
                if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] != 'X') dp[i-1][j-1] = join(dp[i-1][j-1], dp[i][j]);
            }
        }
        if(dp[0][0].first == -1) return {0, 0};
        return {dp[0][0].first, dp[0][0].second};
    }
};