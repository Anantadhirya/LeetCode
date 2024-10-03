class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size();
        int sm = 0, pref = 0, x, ans = n;
        unordered_map<int, int> lst;
        for(const auto &i: nums) {
            (sm += i) %= p;
        }
        lst[0] = -1;
        for(int i = 0; i < n; i++) {
            (pref += nums[i]) %= p;
            lst[pref] = i;
            // pref - x = sm
            // x = pref - sm
            x = (pref - sm + p) % p;
            if(lst.count(x)) ans = min(ans, i - lst[x]);
        }
        return ans == n ? -1 : ans;
    }
};