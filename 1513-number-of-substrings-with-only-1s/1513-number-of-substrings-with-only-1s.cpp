class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        int ans = 0;
        for(int i = 0, j = 0; i < n; i++) {
            if(s[i] == '1') j++;
            else j = 0;
            (ans += j) %= MOD;
        }
        return ans;
    }
};