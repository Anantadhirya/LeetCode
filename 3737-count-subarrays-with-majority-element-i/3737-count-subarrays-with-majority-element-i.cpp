class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0, cnt;
        for(int r = 0; r < n; r++) {
            cnt = 0;
            for(int l = r; l >= 0; l--) {
                cnt += (nums[l] == target);
                ans += (cnt > (r-l+1)/2);
            }
        }
        return ans;
    }
};