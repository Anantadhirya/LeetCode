class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;
        int v, c;
        for(int r = 0; r < n; r++) {
            v = c = 0;
            for(int l = r; l >= 0; l--) {
                if(s[l] == 'a' || s[l] == 'i' || s[l] == 'u' || s[l] == 'e' || s[l] == 'o') v++;
                else c++;
                ans += (v == c && (v*c)%k == 0);
            }
        }
        return ans;
    }
};