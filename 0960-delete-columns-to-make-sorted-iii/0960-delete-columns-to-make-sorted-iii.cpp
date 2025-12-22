class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), ans = 0;
        bool valid;
        vector<int> dp(m, 1);
        for(int i = m-1; i >= 0; i--) {
            for(int j = i+1; j < m; j++) {
                valid = 1;
                for(int k = 0; k < n; k++) {
                    if(strs[k][i] > strs[k][j]) {
                        valid = 0;
                        break;
                    }
                }
                if(valid) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return m - ans;
    }
};