class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = s1.size(), m = s2.size();
        vector<int> cnt(26, 0);
        for(const auto &i: s1) {
            cnt[i-'a']++;
        }
        for(int l = 0, r = 0; r < m; r++) {
            cnt[s2[r]-'a']--;
            while(cnt[s2[r]-'a'] < 0) {
                cnt[s2[l++]-'a']++;
            }
            if(r-l+1 == n) return 1;
        }
        return 0;
    }
};