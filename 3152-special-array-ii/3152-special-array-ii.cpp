class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n, 0);
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + ((nums[i]&1) != (nums[i-1]&1));
        }
        vector<bool> ans;
        for(auto &i: queries) {
            ans.push_back(pref[i[1]] - pref[i[0]] == i[1]-i[0]);
        }
        return ans;
    }
};