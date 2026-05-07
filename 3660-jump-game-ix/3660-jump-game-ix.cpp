class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suff(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = max(nums[i], pref[i-1]);
        }
        suff[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suff[i] = min(nums[i], suff[i+1]);
        }
        for(int i = n-1, j = n-1; i >= 0; i--) {
            if(i+1 < n && pref[i] <= suff[i+1]) j = i;
            nums[i] = pref[j];
        }
        return nums;
    }
};