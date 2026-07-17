class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(mx+1, 0);
        for(int &i: nums) {
            cnt[i]++;
        }
        for(int i = 1; i <= mx; i++) {
            for(int j = 2*i; j <= mx; j += i) {
                cnt[i] += cnt[j];
            }
            cnt[i] = cnt[i] * (cnt[i]-1) / 2;
        }
        for(int i = mx; i >= 1; i--) {
            for(int j = 2*i; j <= mx; j += i) {
                cnt[i] -= cnt[j];
            }
        }
        for(int i = 1; i <= mx; i++) {
            cnt[i] += cnt[i-1];
        }
        int q = queries.size();
        vector<int> ans(q);
        for(int i = 0; i < q; i++) {
            ans[i] = upper_bound(cnt.begin(), cnt.end(), queries[i]) - cnt.begin();
        }
        return ans;
    }
};