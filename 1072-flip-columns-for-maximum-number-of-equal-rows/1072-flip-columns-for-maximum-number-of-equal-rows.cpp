class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bitset<300> b[n];
        int ans = 0, tmp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j]) b[i].set(j);
            }
        }
        for(int i = 0, cnt; i < n; i++) {
            tmp = 0;
            for(int j = 0; j < n; j++) {
                cnt = (b[j] ^ b[i]).count();
                tmp += (cnt == 0 || cnt == m);
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};