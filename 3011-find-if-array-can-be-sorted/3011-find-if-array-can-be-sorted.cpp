class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX, mx = INT_MIN, prefmx = INT_MIN;
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
            if(i+1 == n || __builtin_popcount(nums[i]) != __builtin_popcount(nums[i+1])) {
                if(prefmx > mn) return 0;
                prefmx = mx;
                mn = INT_MAX;
                mx = INT_MIN;
            }
        }
        return 1;
    }
};