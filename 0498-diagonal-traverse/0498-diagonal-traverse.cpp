class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int di = -1, dj = 1;
        vector<int> ans;
        for(int i = 0, j = 0, c = 0; c < n*m; c++) {
            ans.push_back(mat[i][j]);
            i += di;
            j += dj;
            if(i >= n) i--, j += 2, swap(di, dj);
            else if(j >= m) j--, i += 2, swap(di, dj);
            else if(i < 0) i++, swap(di, dj);
            else if(j < 0) j++, swap(di, dj);
        }
        return ans;
    }
};