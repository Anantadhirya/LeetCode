class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int pref_min = 0, pref_max = 0, sm = 0, ans = 0;
        for(const int &i: nums) {
            sm += i;
            ans = max(ans, max(abs(sm - pref_min), abs(sm - pref_max)));
            pref_min = min(pref_min, sm);
            pref_max = max(pref_max, sm);
        }
        return ans;
    }
};