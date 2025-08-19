class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0, j = -1; i < n; i++) {
            if(nums[i] != 0) j = i;
            ans += (long long)i-j;
        }
        return ans;
    }
};