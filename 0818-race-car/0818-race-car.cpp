class Solution {
public:
    int racecar(int target) {
        queue<array<int, 3>> q;
        vector<vector<vector<int>>> dp(2*target+1, vector<vector<int>>(15, vector<int>(2, INT_MAX)));
        vector<vector<vector<bool>>> vis(2*target+1, vector<vector<bool>>(15, vector<bool>(2, 0)));
        dp[0][0][0] = 0;
        q.push({0, 0, 0});
        int i, j, k;
        const auto add = [&](int i, int j, int k, int val) {
            if(0 <= i && i <= 2*target && dp[i][j][k] > val) {
                dp[i][j][k] = val;
                q.push({i, j, k});
            }
        };
        while(!q.empty()) {
            i = q.front()[0];
            j = q.front()[1];
            k = q.front()[2];
            q.pop();
            if(vis[i][j][k]) continue;
            if(i == target) return dp[i][j][k];
            vis[i][j][k] = 1;
            add(i+(k ? -(1<<j) : (1<<j)), j+1, k, dp[i][j][k]+1);
            add(i, 0, 1-k, dp[i][j][k]+1);
        }
        return -1;
    }
};