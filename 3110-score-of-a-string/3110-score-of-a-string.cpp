class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size(), ans = 0;
        for(int i = 1; i < n; i++) {
            ans += abs((int)s[i]-s[i-1]);
        }
        return ans;
    }
};