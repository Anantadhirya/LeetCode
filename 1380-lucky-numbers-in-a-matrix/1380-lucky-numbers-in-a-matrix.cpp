class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = matrix.size(), m = matrix[0].size();
        vector<int> colmax(m, 0);
        int idx;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                colmax[j] = max(colmax[j], matrix[i][j]);
            }
        }
        for(int i = 0; i < n; i++) {
            idx = 0;
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] < matrix[i][idx]) idx = j;
            }
            if(matrix[i][idx] == colmax[idx]) ans.push_back(matrix[i][idx]);
        }
        return ans;
    }
};