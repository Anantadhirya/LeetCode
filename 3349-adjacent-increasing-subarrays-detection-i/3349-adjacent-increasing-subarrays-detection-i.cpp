const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1) return 1;
        int n = nums.size();
        vector<bool> valid(n, 0);
        for(int i = 1, j = 0; i < n; i++) {
            if(nums[i-1] < nums[i]) {
                if(i-j+1 >= k) {
                    valid[i] = 1;
                    if(i-k >= 0 && valid[i-k]) return 1;
                }
            } else j = i;
        }
        return 0;
    }
};