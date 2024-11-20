class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int ans = n;
        vector<int> cnt(3, 0);
        for(auto &i: s) {
            cnt[i -= 'a']++;
        }
        if(cnt[0] < k || cnt[1] < k || cnt[2] < k) return -1;
        for(int l = 0, r = 0; r < n; r++) {
            cnt[s[r]]--;
            while(cnt[s[r]] < k) cnt[s[l++]]++;
            ans = min(ans, n - (r-l+1));
        }
        return ans;
    }
};