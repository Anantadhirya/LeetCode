class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size();
        for(auto &i: nums) {
            if(i <= 0) i = INT_MAX;
        }
        for(const auto &i: nums) {
            if(abs(i) <= n) nums[abs(i)-1] = -abs(nums[abs(i)-1]);
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) return i+1;
        }
        return n+1;
    }
};