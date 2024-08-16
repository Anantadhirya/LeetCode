class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int mn = INT_MAX, mx = INT_MIN, ans = 0;
        for(const auto &i: arrays) {
            if(mx != INT_MIN) ans = max(ans, abs(mx - i[0]));
            if(mn != INT_MAX) ans = max(ans, abs(i.back() - mn));
            mx = max(mx, i.back());
            mn = min(mn, i[0]);
        }
        return ans;
    }
};