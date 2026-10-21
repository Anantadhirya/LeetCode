class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        vector<pair<int, string>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {nums[i].size(), nums[i]};
        }
        sort(v.begin(), v.end());
        return v[n-k].second;
    }
};