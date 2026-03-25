class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long sm = 0, tmp = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sm += grid[i][j];
            }
        }
        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < m; j++) {
                tmp += grid[i][j];
            }
            if(tmp == sm-tmp) return 1;
        }
        tmp = 0;
        for(int j = 0; j < m-1; j++) {
            for(int i = 0; i < n; i++) {
                tmp += grid[i][j];
            }
            if(tmp == sm-tmp) return 1;
        }
        return 0;
    }
};