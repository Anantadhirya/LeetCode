class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<vector<int>> v(m, vector<int>(n, 0));
        for(const auto &i: guards) {
            v[i[0]][i[1]] = 1;
        }
        for(const auto &i: walls) {
            v[i[0]][i[1]] = 2;
        }
        int active;
        for(int i = 0; i < m; i++) {
            active = 0;
            for(int j = 0; j < n; j++) {
                if(v[i][j] == 1) active = 1;
                else if(v[i][j] == 2) active = 0;
                else if(v[i][j] == 0 && active) v[i][j] = -1;
            }
            active = 0;
            for(int j = n-1; j >= 0; j--) {
                if(v[i][j] == 1) active = 1;
                else if(v[i][j] == 2) active = 0;
                else if(v[i][j] == 0 && active) v[i][j] = -1;
            }
        }
        for(int j = 0; j < n; j++) {
            active = 0;
            for(int i = 0; i < m; i++) {
                if(v[i][j] == 1) active = 1;
                else if(v[i][j] == 2) active = 0;
                else if(v[i][j] == 0 && active) v[i][j] = -1;
            }
            active = 0;
            for(int i = m-1; i >= 0; i--) {
                if(v[i][j] == 1) active = 1;
                else if(v[i][j] == 2) active = 0;
                else if(v[i][j] == 0 && active) v[i][j] = -1;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans += (v[i][j] == 0);
            }
        }
        return ans;
    }
};