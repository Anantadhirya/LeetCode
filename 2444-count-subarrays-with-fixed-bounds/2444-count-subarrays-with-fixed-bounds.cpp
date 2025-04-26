class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size();
        int lst = -1, lstMn = -1, lstMx = -1;
        long long ans = 0;
        for(int r = 0; r < n; r++) {
            if(nums[r] < minK || nums[r] > maxK) lst = r;
            if(nums[r] == minK) lstMn = r;
            if(nums[r] == maxK) lstMx = r;
            ans += max(0, min(lstMn, lstMx) - lst);
        }
        return ans;
    }
};