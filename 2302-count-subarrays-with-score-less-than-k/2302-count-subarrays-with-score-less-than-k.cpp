const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long sm = 0, ans = 0;
        for(int l = 0, r = 0; r < n; r++) {
            sm += nums[r];
            while(sm * (r-l+1) >= k) {
                sm -= nums[l++];
            }
            ans += (r-l+1);
        }
        return ans;
    }
};