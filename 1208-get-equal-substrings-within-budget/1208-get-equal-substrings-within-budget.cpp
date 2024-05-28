class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int cost = 0, ans = 0;
        for(int l = 0, r = 0; r < n; r++) {
            cost += abs((int)s[r] - t[r]);
            while(cost > maxCost) {
                cost -= abs((int)s[l] - t[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};