class Solution {
public:
    int appendCharacters(string s, string t) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = s.size(), m = t.size();
        int ans = m;
        for(int i = 0, j = 0; j < m; j++) {
            while(i < n && s[i] != t[j]) i++;
            if(i < n) ans--;
            else break;
            i++;
        }
        return ans;
    }
};