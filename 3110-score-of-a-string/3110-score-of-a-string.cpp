class Solution {
public:
    int scoreOfString(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = s.size(), ans = 0;
        for(int i = 1; i < n; i++) {
            ans += abs((int)s[i]-s[i-1]);
        }
        return ans;
    }
};