int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1));
        vector<pair<int, pair<int, int>>> v;
        int ans = 0, i, j;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                v.push_back({matrix[i][j], {i, j}});
            }
        }
        sort(v.begin(), v.end());
        for(const auto [_, p]: v) {
            i = p.first, j = p.second;
            ans = max(ans, dp[i][j]);
            for(int d = 0, ii, jj; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                if(0 <= ii && ii < n && 0 <= jj && jj < m && matrix[i][j] < matrix[ii][jj]) {
                    dp[ii][jj] = max(dp[ii][jj], dp[i][j] + 1);
                }
            }
        }
        return ans;
    }
};