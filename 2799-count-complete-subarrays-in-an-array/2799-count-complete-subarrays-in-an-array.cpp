class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size(), missing = s.size(), ans = 0;
        for(int l = 0, r = 0; r < n; r++) {
            if(cnt[nums[r]]++ == 0) missing--;
            while(l <= r && missing == 0) if(--cnt[nums[l++]] == 0) missing++;
            ans += l;
        }
        return ans;
    }
};