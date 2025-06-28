class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            v[i] = {-nums[i], i};
        }
        sort(v.begin(), v.end());
        for(int i = n; i > k; i--) v.pop_back();
        for(int i = 0; i < k; i++) v[i] = {v[i].second, -v[i].first};
        sort(v.begin(), v.end());
        for(int i = 0; i < k; i++) ans.push_back(v[i].second);
        return ans;
    }
};