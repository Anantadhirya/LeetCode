class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0, j = 0; i < n; i++) {
            ans[i][j] = rowSum[i];
            colSum[j] -= ans[i][j];
            while(j < m && colSum[j] < 0) {
                if(j+1 < m) {
                    ans[i][j+1] = -colSum[j];
                    colSum[j+1] -= ans[i][j+1];
                }
                ans[i][j] += colSum[j];
                colSum[j] = 0;
                j++;
            }
        }
        return ans;
    }
};