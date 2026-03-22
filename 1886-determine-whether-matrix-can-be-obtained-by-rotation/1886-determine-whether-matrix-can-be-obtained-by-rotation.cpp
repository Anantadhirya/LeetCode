class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        vector<vector<int>> tmp(n, vector<int>(n));
        if(mat == target) return 1;
        for(int d = 0; d < 3; d++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    tmp[i][j] = mat[j][n-1-i];
                }
            }
            swap(mat, tmp);
            if(mat == target) return 1;
        }
        return 0;
    }
};