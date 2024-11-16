class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1);
        int tmp = 0;
        for(int i = 1; i < k; i++) {
            tmp += (nums[i-1] + 1 == nums[i]);
        }
        ans[0] = (tmp == k-1 ? nums[k-1] : -1);
        for(int i = k; i < n; i++) {
            tmp += (nums[i-1] + 1 == nums[i]);
            tmp -= (nums[i-k] + 1 == nums[i-k+1]);
            ans[i-k+1] = (tmp == k-1 ? nums[i] : -1);
        }
        return ans;
    }
};