class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long sm = 0, tmp = 0, rem;
        map<long long, int> cnt, p1, p2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sm += grid[i][j];
                cnt[grid[i][j]]++;
            }
        }
        p2 = cnt;
        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < m; j++) {
                tmp += grid[i][j];
                p1[grid[i][j]]++;
                p2[grid[i][j]]--;
            }
            if(tmp == sm - tmp) return 1;
            rem = tmp - (sm - tmp);
            if(i != 0 && m != 1 && p1[rem] > 0 || rem == grid[0][0] || rem == grid[i][m-1]) return 1;
            if(i != n-2 && m != 1 && p2[-rem] > 0 || -rem == grid[i+1][0] || -rem == grid[n-1][m-1]) return 1;
        }
        tmp = 0;
        p1.clear();
        p2 = cnt;
        for(int j = 0; j < m-1; j++) {
            for(int i = 0; i < n; i++) {
                tmp += grid[i][j];
                p1[grid[i][j]]++;
                p2[grid[i][j]]--;
            }
            if(tmp == sm - tmp) return 1;
            rem = tmp - (sm - tmp);
            if(j != 0 && n != 1 && p1[rem] || rem == grid[0][0] || rem == grid[n-1][j]) return 1;
            if(j != m-2 && n != 1 && p2[-rem] || -rem == grid[0][j+1] || -rem == grid[n-1][m-1]) return 1;
        }
        return 0;
    }
};