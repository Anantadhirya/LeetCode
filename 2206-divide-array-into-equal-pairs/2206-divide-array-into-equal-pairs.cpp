class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool> cnt(500+1, 0);
        int odd = 0;
        for(const auto &i: nums) {
            odd += (cnt[i] ? -1 : 1);
            cnt[i] = 1 - cnt[i];
        }
        return odd == 0;
    }
};