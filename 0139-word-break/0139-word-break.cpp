class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        unordered_set<string> st(d.begin(), d.end());
        int n = s.size();
        vector<bool> dp(n+1, 0);
        string tmp;
        dp[0] = 1;
        for(int i = 0; i <= n; i++) {
            if(dp[i] == 0) continue;
            tmp = "";
            for(int j = i+1; j <= n; j++) {
                tmp += s[j-1];
                if(st.count(tmp)) dp[j] = 1;
            }
        }
        return dp[n];
    }
};