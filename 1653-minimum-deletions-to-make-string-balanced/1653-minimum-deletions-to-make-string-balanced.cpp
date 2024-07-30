class Solution {
public:
    int minimumDeletions(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = s.size();
        vector<int> pref(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + (s[i-1] == 'a');
        }
        int ans = 0;
        for(int i = 0, al, br; i <= n; i++) {
            al = pref[i];
            br = n-i - (pref[n] - pref[i]);
            ans = max(ans, al + br);
        }
        return n - ans;
    }
};