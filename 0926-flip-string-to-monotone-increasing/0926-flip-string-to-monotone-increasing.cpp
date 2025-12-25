class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size(), cnt = 0, tmp = 0, ans = n;
        for(char &c: s) cnt += (c == '1');
        ans = min(ans, min(n-cnt, cnt));
        for(int i = 0; i < n; i++) {
            tmp += (s[i] == '1');
            ans = min(ans, tmp + (n-i-1) - (cnt-tmp));
        }
        return ans;
    }
};