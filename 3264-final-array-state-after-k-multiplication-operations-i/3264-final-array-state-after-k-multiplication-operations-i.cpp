class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int idx;
        int n = nums.size();
        while(k--) {
            idx = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] < nums[idx]) idx = i;
            }
            nums[idx] *= multiplier;
        }
        return nums;
    }
};