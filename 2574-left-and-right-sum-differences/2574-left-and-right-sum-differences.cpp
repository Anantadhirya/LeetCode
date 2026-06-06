class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n+2, 0), suff(n+2, 0);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + nums[i-1];
        }
        for(int i = n; i >= 1; i--) {
            suff[i] = suff[i+1] + nums[i-1];
        }
        for(int i = 1; i <= n; i++) {
            nums[i-1] = abs(pref[i-1] - suff[i+1]);
        }
        return nums;
    }
};