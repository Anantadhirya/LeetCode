class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        long long sum = 0;
        for(const auto &i: nums) {
            sum += i;
        }
        long long pref = 0;
        int ans = 0;
        nums.pop_back();
        for(const auto &i: nums) {
            pref += i;
            ans += (pref >= sum - pref);
        }
        return ans;
    }
};