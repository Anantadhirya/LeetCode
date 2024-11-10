class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<vector<pair<int, int>>> v(2);
        int n = nums.size();
        int ans = n+1;
        for(int r = 0; r < n; r++) {
            swap(v[0], v[1]);
            v[0].clear();
            v[0].push_back({nums[r], r});
            for(auto &[val, l]: v[1]) {
                if(v[0].back().first != val) {
                    v[0].push_back({val | nums[r], l});
                }
            }
            for(auto &[val, l]: v[0]) {
                if(val >= k) ans = min(ans, r-l+1);
            }
        }
        return ans == n+1 ? -1 : ans;
    }
};