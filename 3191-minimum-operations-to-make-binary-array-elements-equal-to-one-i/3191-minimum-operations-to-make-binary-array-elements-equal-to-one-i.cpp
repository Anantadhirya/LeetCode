const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] == 0) {
                ans++;
                if(i-2 < 0) return -1;
                nums[i-1] = 1 - nums[i-1];
                nums[i-2] = 1 - nums[i-2];
            }
        }
        return ans;
    }
};