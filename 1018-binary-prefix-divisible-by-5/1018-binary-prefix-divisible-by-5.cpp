class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n);
        for(int i = 0, x = 0; i < n; i++) {
            x = (2*x + nums[i]) % 5;
            ans[i] = (x == 0);
        }
        return ans;
    }
};