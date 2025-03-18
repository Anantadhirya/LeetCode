class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        const int MX = 32;
        vector<int> cnt(32, 0);
        int ans = 0, n = nums.size(), more = 0;
        for(int i = 0, j = 0; i < n; i++) {
            for(int k = 0; k < MX; k++) {
                if((nums[i]>>k)&1) {
                    more += (cnt[k] == 1);
                    cnt[k]++;
                }
            }
            while(more) {
                for(int k = 0; k < MX; k++) {
                    if((nums[j]>>k)&1) {
                        cnt[k]--;
                        more -= (cnt[k] == 1);
                    }
                }
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};