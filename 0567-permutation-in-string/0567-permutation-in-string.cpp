class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        unordered_map<char, int> cnt;
        for(const auto &i: s1) {
            cnt[i]++;
        }
        for(int l = 0, r = 0; r < m; r++) {
            cnt[s2[r]]--;
            while(cnt[s2[r]] < 0) {
                cnt[s2[l++]]++;
            }
            if(r-l+1 == n) return 1;
        }
        return 0;
    }
};