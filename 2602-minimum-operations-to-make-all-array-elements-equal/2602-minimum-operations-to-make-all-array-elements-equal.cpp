class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> pref(n+1, 0);
        vector<long long> ans;
        int idx;
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + nums[i-1];
        }
        for(int &i: queries) {
            idx = lower_bound(nums.begin(), nums.end(), i) - nums.begin() + 1;
            ans.push_back(((pref[n] - pref[idx-1]) - (long long)i * (n-idx+1)) + ((long long)i * (idx-1) - pref[idx-1]));
        }
        return ans;
    }
};