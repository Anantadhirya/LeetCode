class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        set<int> s[2];
        int ans = 0;
        for(int i = 0; i < n; i++) {
            s[0].clear();
            s[1].clear();
            for(int j = i; j >= 0; j--) {
                s[nums[j]&1].insert(nums[j]);
                if(s[0].size() == s[1].size()) ans = max(ans, i-j+1);
            }
        }
        return ans;
    }
};