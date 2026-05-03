class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int n = nums.size();
        vector<int> cnt(1001, 0);
        pair<int, int> ans = {0, -1};
        for(int i = 1; i < n; i++) {
            if(nums[i-1] != key) continue;
            ans = max(ans, {++cnt[nums[i]], nums[i]});
        }
        return ans.second;
    }
};