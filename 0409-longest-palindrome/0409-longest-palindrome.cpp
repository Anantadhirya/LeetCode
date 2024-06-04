class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;
        int ans = s.size();
        bool b = 0;
        for(const char &c: s) {
            cnt[c]++;
        }
        for(const auto &[_, c]: cnt) {
            if(c&1) {
                ans--;
                b = 1;
            }
        }
        ans += b;
        return ans;
    }
};