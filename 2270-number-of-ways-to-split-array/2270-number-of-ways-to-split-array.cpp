class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0, pref = 0;
        int ans = 0;
        for(const auto &i: nums) {
            sum += i;
        }
        nums.pop_back();
        for(const auto &i: nums) {
            pref += i;
            ans += (pref >= sum - pref);
        }
        return ans;
    }
};