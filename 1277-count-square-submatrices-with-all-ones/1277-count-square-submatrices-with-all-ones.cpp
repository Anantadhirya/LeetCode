class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i) matrix[i][j] += matrix[i-1][j];
                if(j) matrix[i][j] += matrix[i][j-1];
                if(i && j) matrix[i][j] -= matrix[i-1][j-1];
            }
        }
        int ans = 0, tmp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int l = 1; l <= max(i, j) + 1; l++) {
                    tmp = matrix[i][j];
                    if(i-l >= 0) tmp -= matrix[i-l][j];
                    if(j-l >= 0) tmp -= matrix[i][j-l];
                    if(i-l >= 0 && j-l >= 0) tmp += matrix[i-l][j-l];
                    if(tmp == l*l) ans++;
                    else break;
                }
            }
        }
        return ans;
    }
};