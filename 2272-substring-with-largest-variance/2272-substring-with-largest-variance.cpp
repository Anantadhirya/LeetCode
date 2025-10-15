class Solution {
public:
    int largestVariance(string s) {
        int ans = 0, mx, pref, pref2, cnti, cntj;
        int n = s.size();
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                if(j == i) continue;
                pref = pref2 = cnti = cntj = 0;
                mx = INT_MIN;
                for(int l = 0, r = 0; r < n; r++) {
                    if(s[r]-'a' == i) pref += 1, cnti++;
                    else if(s[r]-'a' == j) pref -= 1, cntj++;
                    while(cnti > 0 && cntj > 0) {
                        mx = max(mx, -pref2);
                        if(s[l]-'a' == i) pref2 += 1, cnti--;
                        else if(s[l] - 'a' == j) pref2 -= 1, cntj--;
                        l++;
                    }
                    if(mx != INT_MIN) ans = max(ans, pref+mx);
                }
            }
        }
        return ans;
    }
};