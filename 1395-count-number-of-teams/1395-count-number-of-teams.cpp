class Solution {
public:
    int numTeams(vector<int>& rating) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = rating.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(rating[j] < rating[i]) {
                    dp[i][0]++;
                    ans += dp[j][0];
                }
                if(rating[j] > rating[i]) {
                    dp[i][1]++;
                    ans += dp[j][1];
                }
            }
        }
        return ans;
    }
};