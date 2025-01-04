class Solution {
public:
    int countPalindromicSubsequence(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = s.size();
        int ans = 0, cnt;
        bitset<26> b;
        for(int i = 0, l, r, j; i < 26; i++) {
            for(l = 0; l < n; l++) {
                if(s[l]-'a' == i) break;
            }
            for(r = n-1; r >= 0; r--) {
                if(s[r]-'a' == i) break;
            }
            b = 0;
            cnt = 0;
            for(j = l+1; j < r; j++) {
                if(b[s[j]-'a']) continue;
                b.set(s[j]-'a');
                cnt++;
            }
            ans += cnt;
        }
        return ans;
    }
};