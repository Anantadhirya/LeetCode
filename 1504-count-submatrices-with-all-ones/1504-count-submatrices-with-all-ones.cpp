class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) mat[i][j] += mat[i][j-1];
        }
        for(int l = 0; l < m; l++) {
            for(int r = l; r < m; r++) {
                for(int i = 0, j = 0; i < n; i++) {
                    if(mat[i][r] - (l-1 >= 0 ? mat[i][l-1] : 0) == r-l+1) j++;
                    else j = 0;
                    ans += j;
                }
            }
        }
        return ans;
    }
};