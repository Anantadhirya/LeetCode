class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> cnt(n+1);
        int ans = 0;
        cnt[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(const auto &[u, v]: cnt[i-1]) {
                cnt[i][u] += v;
                cnt[i][u^nums[i-1]] += v;
            }
        }
        for(const auto &[u, v]: cnt[n]) {
            ans += u * v;
        }
        return ans;
    }
};