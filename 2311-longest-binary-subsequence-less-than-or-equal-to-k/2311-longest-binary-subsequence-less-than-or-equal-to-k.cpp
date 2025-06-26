class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0, n = s.size();
        for(const char &c: s) {
            if(c == '0') ans++;
        }
        for(int i = n-1, j = 1; i >= 0 && j <= k; i--) {
            if(s[i] == '1') k -= j, ans++;
            j <<= 1;
        }
        return ans;
    }
};