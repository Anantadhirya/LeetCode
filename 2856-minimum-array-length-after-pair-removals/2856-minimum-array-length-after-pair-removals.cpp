class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        for(int i = 0, j; i < n; i = j) {
            for(j = i+1; j < n && nums[j] == nums[i]; ) j++;
            mx = max(mx, j-i);
        }
        if(mx <= n/2) return (n&1);
        return mx - (n - mx);
    }
};