class Solution {
public:
    long long findScore(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        long long ans = 0;
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }
        sort(v.begin(), v.end());
        for(const auto &[i, idx]: v) {
            if(nums[idx] == 0) continue;
            ans += (long long)i;
            nums[idx] = 0;
            if(idx != 0) nums[idx-1] = 0;
            if(idx != n-1) nums[idx+1] = 0;
        }
        return ans;
    }
};