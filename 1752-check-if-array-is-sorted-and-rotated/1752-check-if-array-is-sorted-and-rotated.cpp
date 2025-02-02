class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = (nums[0] < nums[n-1]);
        for(int i = 0; i < n-1; i++) {
            cnt += (nums[i+1] < nums[i]);
        }
        return cnt <= 1;
    }
};