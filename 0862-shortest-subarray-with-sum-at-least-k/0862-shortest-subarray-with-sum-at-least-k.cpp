class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int inf = INT_MAX;
        int n = nums.size(), ans = inf;
        long long pref = 0;
        vector<pair<long long, int>> s(1, {0, -1});
        for(int i = 0; i < n; i++) {
            pref += (long long)nums[i];
            // pref - x >= k
            // pref - k >= x
            auto it = lower_bound(s.begin(), s.end(), make_pair(pref - k + 1, -1));
            if(it != s.begin()) {
                --it;
                ans = min(ans, i - it->second);
            }
            while(!s.empty() && s.back().first >= pref) s.pop_back();
            s.push_back({pref, i});
        }
        return ans == inf ? -1 : ans;
    }
};