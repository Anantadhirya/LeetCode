class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int ans = n;
        vector<int> cnt(3, 0);
        for(int i = 0; i < n; i++) {
            cnt[s[i]-'a']++;
        }
        if(cnt[0] < k || cnt[1] < k || cnt[2] < k) return -1;
        for(int l = 0, r = 0, t; r < n; r++) {
            t = s[r]-'a';
            cnt[t]--;
            while(cnt[t] < k) cnt[s[l++]-'a']++;
            ans = min(ans, n - (r-l+1));
        }
        return ans;
    }
};