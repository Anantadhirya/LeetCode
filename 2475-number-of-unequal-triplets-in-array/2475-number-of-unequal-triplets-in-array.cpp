class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] == nums[j]) continue;
                for(int k = j+1; k < n; k++) ans += (nums[k] != nums[i] && nums[k] != nums[j]);
            }
        }
        return ans;
    }
};