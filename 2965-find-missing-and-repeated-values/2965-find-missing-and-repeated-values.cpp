class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnt(n*n, 0);
        vector<int> ans(2);
        for(const auto &row: grid) {
            for(const auto &i: row) {
                cnt[i-1]++;
            }
        }
        for(int i = n*n; i >= 1; i--) {
            if(cnt[i-1] == 0) ans[1] = i;
            if(cnt[i-1] == 2) ans[0] = i;
        }
        return ans;
    }
};