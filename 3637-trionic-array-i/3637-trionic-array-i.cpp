class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), dir = 1, cnt = 0;
        if(nums[0] > nums[1]) return 0;
        for(int i = 1; i < n; i++) {
            if(nums[i-1] == nums[i]) return 0;
            if(nums[i-1] < nums[i]) {
                if(dir == -1) dir = 1, cnt++;
            } else {
                if(dir == 1) dir = -1, cnt++;
            }
        }
        return cnt == 2;
    }
};