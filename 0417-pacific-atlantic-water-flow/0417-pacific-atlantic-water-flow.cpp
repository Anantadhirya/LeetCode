int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> v1(n, vector<bool>(m, 0)), v2(n, vector<bool>(m, 0));
        vector<vector<int>> ans;
        queue<pair<int, int>> q1, q2;
        int curi, curj;
        for(int i = 0; i < n; i++) {
            q1.push({i, 0});
            q2.push({i, m-1});
        }
        for(int i = 0; i < m; i++) {
            q1.push({0, i});
            q2.push({n-1, i});
        }
        while(!q1.empty()) {
            curi = q1.front().first;
            curj = q1.front().second;
            q1.pop();
            if(v1[curi][curj]) continue;
            v1[curi][curj] = 1;
            for(int d = 0, ii, jj; d < 4; d++) {
                ii = curi + dx[d];
                jj = curj + dy[d];
                if(0 <= ii && ii < n && 0 <= jj && jj < m && !v1[ii][jj] && heights[ii][jj] >= heights[curi][curj]) {
                    q1.push({ii, jj});
                }
            }
        }
        while(!q2.empty()) {
            curi = q2.front().first;
            curj = q2.front().second;
            q2.pop();
            if(v2[curi][curj]) continue;
            v2[curi][curj] = 1;
            for(int d = 0, ii, jj; d < 4; d++) {
                ii = curi + dx[d];
                jj = curj + dy[d];
                if(0 <= ii && ii < n && 0 <= jj && jj < m && !v2[ii][jj] && heights[ii][jj] >= heights[curi][curj]) {
                    q2.push({ii, jj});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v1[i][j] && v2[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};