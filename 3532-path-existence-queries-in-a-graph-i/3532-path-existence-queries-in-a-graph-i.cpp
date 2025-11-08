class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> c(n);
        vector<bool> ans;
        c[0] = 0;
        for(int i = 1; i < n; i++) {
            c[i] = c[i-1] + (nums[i] - nums[i-1] > maxDiff);
        }
        for(auto i: queries) {
            ans.push_back(c[i[0]] == c[i[1]]);
        }
        return ans;
    }
};