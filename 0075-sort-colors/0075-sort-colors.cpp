class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0, j = 0; i < n; ) {
            if(nums[i] == 0) swap(nums[i], nums[j++]), i++;
            else if(nums[i] == 2) n--, swap(nums[i], nums[n]);
            else i++;
        }
    }
};