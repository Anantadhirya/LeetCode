const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0, j = 0, l = 0, r = 0, val = nums[0]; val <= nums.back(); val++) {
            while(i < n && nums[i] < val) i++;
            while(j < n && nums[j] <= val) j++;
            while(l < n && nums[l] < val - k) l++;
            while(r < n && nums[r] <= val + k) r++;
            ans = max(ans, (j-i) + min(numOperations, (r-l) - (j-i)));
        }
        return ans;
    }
};