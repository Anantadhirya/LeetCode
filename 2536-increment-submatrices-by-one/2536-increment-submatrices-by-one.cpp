const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int r1, c1, r2, c2;
        for(auto i: queries) {
            r1 = i[0], c1 = i[1], r2 = i[2], c2 = i[3];
            ans[r1][c1]++;
            if(r2+1 < n) ans[r2+1][c1]--;
            if(c2+1 < n) ans[r1][c2+1]--;
            if(r2+1 < n && c2+1 < n) ans[r2+1][c2+1]++;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i-1 >= 0) ans[i][j] += ans[i-1][j];
                if(j-1 >= 0) ans[i][j] += ans[i][j-1];
                if(i-1 >= 0 && j-1 >= 0) ans[i][j] -= ans[i-1][j-1];
            }
        }
        return ans;
    }
};