class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> lst(n+1);
        int ans = INT_MAX;
        for(int i = 0, j, k, sz; i < n; i++) {
            sz = lst[nums[i]].size();
            if(sz >= 2) {
                j = lst[nums[i]][sz-1];
                k = lst[nums[i]][sz-2];
                ans = min(ans, abs(i-j) + abs(j-k) + abs(i-k));
            }
            lst[nums[i]].push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};