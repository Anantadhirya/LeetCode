class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
        bool op;
        for(int r = 0; r < n; r++) {
            for(int l = r; l >= 0; l--) {
                op = 0;
                for(int k = l; k <= r; k++) {
                    if(s[k] == '+' || s[k] == '-' || s[k] == '*') {
                        op = 1;
                        for(const auto &a: dp[l][k-1]) {
                            for(const auto &b: dp[k+1][r]) {
                                if(s[k] == '+') dp[l][r].push_back(a+b);
                                else if(s[k] == '-') dp[l][r].push_back(a-b);
                                else if(s[k] == '*') dp[l][r].push_back(a*b);
                            }
                        }
                    }
                }
                if(!op) dp[l][r].push_back(stoi(s.substr(l, r-l+1)));
            }
        }
        return dp[0][n-1];
    }
};