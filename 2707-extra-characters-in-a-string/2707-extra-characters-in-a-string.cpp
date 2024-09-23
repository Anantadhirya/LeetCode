class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = s.size();
        vector<int> dp(n+1, 0);
        bool sama;
        int sz;
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            for(const auto &j: dictionary) {
                sama = 1;
                sz = j.size();
                if(i-sz < 0) continue;
                for(int k = 1; k <= sz; k++) {
                    if(s[i-k] != j[sz-k]) {
                        sama = 0;
                        break;
                    }
                }
                if(sama) {
                    dp[i] = max(dp[i], dp[i-sz] + sz);
                }
            }
        }
        return n - dp[n];
    }
};