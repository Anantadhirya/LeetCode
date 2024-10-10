class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<pair<int, int>> v;
        int ans = 0, mn;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        mn = v[0].second;
        for(const auto &[_, i]: v) {
            ans = max(ans, i - mn);
            mn = min(mn, i);
        }
        return ans;
    }
};