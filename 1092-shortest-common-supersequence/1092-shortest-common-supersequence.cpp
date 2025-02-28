const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(m+1, {INT_MAX, 0}));
        string ans;
        dp[0][0] = {0, 0};
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i && j && str1[i-1] == str2[j-1]) dp[i][j] = min(dp[i][j], {dp[i-1][j-1].first+1, 1});
                if(j) dp[i][j] = min(dp[i][j], {dp[i][j-1].first + 1, 2});
                if(i) dp[i][j] = min(dp[i][j], {dp[i-1][j].first + 1, 3});
            }
        }
        for(int i = n, j = m; i > 0 || j > 0; ) {
            if(dp[i][j].second == 1) ans.push_back(str1[i-1]), i--, j--;
            else if(dp[i][j].second == 2) ans.push_back(str2[j-1]), j--;
            else ans.push_back(str1[i-1]), i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};