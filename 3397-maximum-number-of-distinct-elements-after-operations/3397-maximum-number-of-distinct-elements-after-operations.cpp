class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int ans = 0, cur = INT_MIN;
        sort(nums.begin(), nums.end());
        for(auto i: nums) {
            if(cur+1 < i-k) {
                cur = i-k;
                ans++;
            } else if(cur+1 <= i+k) {
                cur++;
                ans++;
            }
        }
        return ans;
    }
};