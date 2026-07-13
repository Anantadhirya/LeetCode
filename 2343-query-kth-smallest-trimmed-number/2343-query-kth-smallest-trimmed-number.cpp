class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = nums[0].size();
        vector<pair<string, int>> v(n);
        vector<int> ans;
        int k, t;
        for(auto &q: queries) {
            k = q[0], t = q[1];
            for(int i = 0; i < n; i++) {
                v[i] = {nums[i].substr(m-t), i};
            }
            sort(v.begin(), v.end());
            ans.push_back(v[k-1].second);
        }
        return ans;
    }
};