const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();
class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        const int inf = INT_MAX;
        int n = s.size();
        s.push_back('1');
        vector<int> dp(n+1, inf);
        dp[n] = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '0') continue;
            for(int j = i, x = 0, tmp; j < n; j++) {
                x = 2*x + (s[j] == '1');
                if(s[j+1] == '0' || dp[j+1] == inf) continue;
                tmp = x;
                while(tmp % 5 == 0) tmp /= 5;
                if(tmp == 1) dp[i] = min(dp[i], dp[j+1] + 1);
            }
        }
        return dp[0] == inf ? -1 : dp[0];
    }
};