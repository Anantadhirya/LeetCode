class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            for(int j = i-1, k = 0; k < j; j--) {
                while(k < j && nums[k] <= nums[i] - nums[j]) k++;
                ans += j-k;
            }
        }
        return ans;
    }
};