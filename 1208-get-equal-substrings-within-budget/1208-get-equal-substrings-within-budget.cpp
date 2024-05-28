class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = s.size();
        int cost = 0, ans = 0;
        for(int l = 0, r = 0; r < n; r++) {
            cost += s[r] = abs((int)s[r] - t[r]);
            while(cost > maxCost) {
                cost -= s[l++];
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};