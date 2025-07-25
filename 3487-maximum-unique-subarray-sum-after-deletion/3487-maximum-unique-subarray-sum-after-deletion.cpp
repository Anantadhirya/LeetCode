class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(i+1 < n && nums[i] == nums[i+1]) continue;
            ans += max(0, nums[i]);
        }
        if(nums.back() < 0) ans += nums.back();
        return ans;
    }
};