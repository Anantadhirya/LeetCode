class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        vector<vector<long long>> dp(n, vector<long long>(12, 0));
        vector<string> st = {"ryr", "ryg", "rgr", "rgy", "yry", "yrg", "ygr", "ygy", "gry", "grg", "gyr", "gyg"};
        vector<vector<int>> adj(12);
        for(int j = 0, valid; j < 12; j++) {
            for(int k = 0; k < 12; k++) {
                valid = 1;
                for(int l = 0; l < 3; l++) {
                    if(st[j][l] == st[k][l]) {
                        valid = 0;
                        break;
                    }
                }
                if(valid) adj[j].push_back(k);
            }
        }
        dp[0].assign(12, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 12; j++) {
                for(int &k: adj[j]) {
                    (dp[i][j] += dp[i-1][k]) %= MOD;
                }
            }
        }
        for(int j = 0; j < 12; j++) {
            (ans += dp[n-1][j]) %= MOD;
        }
        return ans;
    }
};