class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int mx = nums.back();
        for(int i = 0, j = 0, l = 0, r = 0, val = 1; val <= mx; val++) {
            while(i < n && nums[i] < val) i++;
            while(j < n && nums[j] <= val) j++;
            while(l < n && nums[l] < val - k) l++;
            while(r < n && nums[r] <= val + k) r++;
            ans = max(ans, (j-i) + min(numOperations, (r-l) - (j-i)));
        }
        return ans;
    }
};