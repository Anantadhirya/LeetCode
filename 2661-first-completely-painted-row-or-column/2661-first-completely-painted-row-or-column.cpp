class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = mat.size(), m = mat[0].size();
        int k = n*m;
        vector<int> row(k), col(k), rc(n, 0), cc(m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                row[mat[i][j]-1] = i;
                col[mat[i][j]-1] = j;
            }
        }
        for(int i = 0; i < k; i++) {
            if(++rc[row[arr[i]-1]] == m) return i;
            if(++cc[col[arr[i]-1]] == n) return i;
        }
        return -1;
    }
};