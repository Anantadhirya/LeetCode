class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans, sm, n = nums.size();
        ans = sm = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] <= nums[i-1]) sm = 0;
            sm += nums[i];
            ans = max(ans, sm);
        }
        return ans;
    }
};