class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int ans = 0;
        for(auto &i: queries) {
            for(int j = i[0]; j <= i[1]; j += i[2]) {
                nums[j] = ((long long)nums[j] * i[3]) % MOD;
            }
        }
        for(int &i: nums) ans ^= i;
        return ans;
    }
};