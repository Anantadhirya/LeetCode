class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        int ans = 0;
        for(int j = 0; j < m; j++) {
            for(int i = 0, lst = -1; i < n; i++) {
                if(matrix[i][j] == 0) lst = i;
                v[i][j] = i - lst;
            }
        }
        for(int i = 0; i < n; i++) {
            sort(v[i].begin(), v[i].end());
            for(int j = 0; j < m; j++) {
                ans = max(ans, v[i][j] * (m - j));
            }
        }
        return ans;
    }
};