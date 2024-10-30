class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size();
        vector<int> pref(n, 0), suff(n, 0);
        vector<int> v;
        int ans = 0;
        for(int i = 0, j; i < n; i++) {
            j = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            pref[i] = j+1;
            if(j == v.size()) v.push_back(nums[i]);
            else v[j] = nums[i];
        }
        v.clear();
        for(int i = n-1, j; i >= 0; i--) {
            j = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            suff[i] = j+1;
            if(j == v.size()) v.push_back(nums[i]);
            else v[j] = nums[i];
        }
        for(int i = 1; i < n-1; i++) {
            if(pref[i] == 1 || suff[i] == 1) continue;
            ans = max(ans, pref[i] + suff[i] - 1);
        }
        return n - ans;
    }
};