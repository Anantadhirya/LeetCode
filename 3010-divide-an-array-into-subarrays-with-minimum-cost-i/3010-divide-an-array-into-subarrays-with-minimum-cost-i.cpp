const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX, mn2 = INT_MAX;
        for(int i = 1; i < n; i++) {
            if(nums[i] < mn2) mn2 = nums[i];
            if(mn2 < mn) swap(mn2, mn);
        }
        return nums[0] + mn + mn2;
    }
};