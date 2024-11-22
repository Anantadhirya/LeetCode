class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bitset<300> b[n], mask;
        unordered_map<bitset<300>, int> cnt;
        for(int j = 0; j < m; j++) {
            mask.set(j);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j]) b[i].set(j);
            }
            cnt[b[i]]++;
            ans = max(ans, cnt[b[i]] + cnt[b[i]^mask]);
        }
        return ans;
    }
};