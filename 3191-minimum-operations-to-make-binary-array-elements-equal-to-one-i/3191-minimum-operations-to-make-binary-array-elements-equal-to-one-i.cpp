class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = n-1; i-2 >= 0; i--) {
            if(nums[i] == 0) {
                ans++;
                nums[i-1] ^= 1;
                nums[i-2] ^= 1;
            }
        }
        if(nums[0] == 0 || nums[1] == 0) return -1;
        return ans;
    }
};