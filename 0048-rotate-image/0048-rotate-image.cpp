class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int l = 0, r = n-1; l < r; l++, r--) {
                swap(matrix[i][l], matrix[i][r]);
            }
        }
    }
};