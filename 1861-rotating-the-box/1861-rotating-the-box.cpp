class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = box[n-1-j][i];
            }
        }
        for(int j = 0, cnt; j < n; j++) {
            cnt = 0;
            for(int i = 0; i <= m; i++) {
                if(i == m || ans[i][j] == '*') {
                    for(int k = 1; k <= cnt; k++) {
                        ans[i-k][j] = '#';
                    }
                    cnt = 0;
                } else if(ans[i][j] == '#') {
                    ans[i][j] = '.';
                    cnt++;
                }
            }
        }
        return ans;
    }
};