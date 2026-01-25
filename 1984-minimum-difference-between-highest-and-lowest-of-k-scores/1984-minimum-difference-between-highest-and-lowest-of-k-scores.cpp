const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = k-1; i < n; i++) {
            ans = min(ans, nums[i] - nums[i-k+1]);
        }
        return ans;
    }
};