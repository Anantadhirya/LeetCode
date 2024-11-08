class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n);
        int tmp = 0, mx = (1<<maximumBit)-1;
        for(int i = 0; i < n; i++) {
            tmp ^= nums[i];
            ans[n-i-1] = mx ^ tmp;
        }
        return ans;
    }
};