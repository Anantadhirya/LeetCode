class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> cnt(2e5 + 5, 0);
        int ans = 0;
        for(const int &i: nums) {
            cnt[i]++;
        }
        for(int i = 0; i <= 2e5; i++) {
            if(cnt[i] > 1) {
                ans += cnt[i] - 1;
                cnt[i+1] += cnt[i] - 1;
            }
        }
        return ans;
    }
};