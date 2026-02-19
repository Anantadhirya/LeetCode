class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int cur = 1, prev = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(i == n || s[i] != s[i-1]) {
                ans += min(prev, cur);
                prev = cur;
                cur = 1;
            } else cur++;
        }
        return ans;
    }
};