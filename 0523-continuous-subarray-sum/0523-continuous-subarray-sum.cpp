class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, bool> m;
        int pref = 0, pref2 = 0;
        for(const int &i: nums) {
            (pref += i) %= k;
            if(m[pref]) return 1;
            m[pref2] = 1;
            pref2 = pref;
        }
        return 0;
    }
};