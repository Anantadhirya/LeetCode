class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> ans(query_row+1, vector<double>(query_row+1, 0));
        ans[0][0] = poured;
        for(int i = 1; i <= query_row; i++) {
            for(int j = 0; j <= i; j++) {
                ans[i][j] = max(0.00, ans[i-1][j]-1)/2 + (j-1 >= 0 ? max(0.00, ans[i-1][j-1]-1) : 0)/2;
            }
        }
        return min(1.00, ans[query_row][query_glass]);
    }
};