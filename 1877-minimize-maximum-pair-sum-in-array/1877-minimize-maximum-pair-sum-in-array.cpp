class Solution {
public:
    int minPairSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n-i-1; i++) {
            ans = max(ans, nums[i] + nums[n-i-1]);
        }
        return ans;
    }
};