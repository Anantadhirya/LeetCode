class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        bitset<101> b;
        int cnt, ans = 0;
        for(int r = 0; r < n; r++) {
            b = 0;
            cnt = 0;
            for(int l = r; l >= 0; l--) {
                if(!b[nums[l]]) {
                    b[nums[l]] = 1, cnt++;
                }
                ans += cnt*cnt;
            }
        }
        return ans;
    }
};