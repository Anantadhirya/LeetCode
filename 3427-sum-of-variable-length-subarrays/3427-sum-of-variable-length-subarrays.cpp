class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        int pref = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            pref += nums[i];
            ans += pref - (i - nums[i] - 1 >= 0 ? nums[i - nums[i] - 1] : 0);
            nums[i] = pref;
        }
        return ans;
    }
};