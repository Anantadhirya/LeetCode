class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size();
        int inf = n+1;
        long long pref = 0;
        int ans = inf, sz = 0;
        vector<pair<long long, int>> s(n+1);
        s[sz++] = {0, -1};
        for(int i = 0, j = 0; i < n; i++) {
            pref += (long long)nums[i];
            while(j < sz && pref - s[j].first >= k) {
                ans = min(ans, i - s[j++].second);
            }
            while(sz > 0 && s[sz-1].first >= pref) {
                sz--;
            }
            s[sz++] = {pref, i};
        }
        return ans == inf ? -1 : ans;
    }
};