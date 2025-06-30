const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for(int i = 0, j = 1; i < n; i++) {
            while(j < n && nums[j] <= nums[i] + 1) j++;
            if(nums[i] + 1 == nums[j-1]) ans = max(ans, j-i);
        }
        return ans;
    }
};