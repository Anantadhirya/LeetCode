class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bool ab = nums[0] == nums[1];
        bool bc = nums[1] == nums[2];
        if(nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[2] + nums[1] <= nums[0]) return "none";
        if(ab && bc) return "equilateral";
        if(ab || bc) return "isosceles";
        return "scalene";
    }
};