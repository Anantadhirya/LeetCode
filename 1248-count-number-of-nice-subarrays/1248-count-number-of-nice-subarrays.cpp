class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> v;
        int n = nums.size(), ans = 0;
        v.push_back(-1);
        for(int i = 0; i < n; i++) {
            if(nums[i]&1) v.push_back(i);
        }
        v.push_back(n);
        for(int i = v.size()-2; i >= k; i--) {
            ans += (v[i+1] - v[i]) * (v[i-k+1] - v[i-k]);
        }
        return ans;
    }
};