class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        vector<int> cnt(2005, 0);
        bitset<2005> b;
        int n = nums.size(), missing = 0, ans = 0;
        for(const int &i: nums) if(!b[i]) b[i] = 1, missing++;
        for(int l = 0, r = 0; r < n; r++) {
            if(cnt[nums[r]]++ == 0) missing--;
            while(l <= r && missing == 0) if(--cnt[nums[l++]] == 0) missing++;
            ans += l;
        }
        return ans;
    }
};