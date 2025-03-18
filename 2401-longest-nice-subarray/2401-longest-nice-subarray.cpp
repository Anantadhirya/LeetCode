class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask = 0;
        int ans = 0, n = nums.size();
        for(int i = 0, j = 0; i < n; i++) {
            while(mask & nums[i]) {
                mask ^= nums[j++];
            }
            mask ^= nums[i];
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};