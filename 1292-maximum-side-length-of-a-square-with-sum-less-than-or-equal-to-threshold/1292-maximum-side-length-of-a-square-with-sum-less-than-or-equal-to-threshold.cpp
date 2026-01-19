class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pref(n, vector<int>(m, 0));
        int tmp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pref[i][j] = mat[i][j];
                if(i-1 >= 0) pref[i][j] += pref[i-1][j];
                if(j-1 >= 0) pref[i][j] += pref[i][j-1];
                if(i-1 >= 0 && j-1 >= 0) pref[i][j] -= pref[i-1][j-1];
            }
        }
        for(int k = min(n, m); k >= 1; k--) {
            for(int i = 0; i+k-1 < n; i++) {
                for(int j = 0; j+k-1 < m; j++) {
                    tmp = pref[i+k-1][j+k-1];
                    if(i-1 >= 0) tmp -= pref[i-1][j+k-1];
                    if(j-1 >= 0) tmp -= pref[i+k-1][j-1];
                    if(i-1 >= 0 && j-1 >= 0) tmp += pref[i-1][j-1];
                    if(tmp <= threshold) return k;
                }
            }
        }
        return 0;
    }
};