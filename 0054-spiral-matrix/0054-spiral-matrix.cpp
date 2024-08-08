class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        const int inf = INT_MAX;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int d = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int r = 0, c = 0, rr, cc;
        auto check = [&]() {
            rr = r + dr[d];
            cc = c + dc[d];
            return (0 <= rr && rr < n && 0 <= cc && cc < m && matrix[rr][cc] != inf);
        };
        while(1) {
            ans.push_back(matrix[r][c]);
            if(ans.size() == n * m) break;
            matrix[r][c] = inf;
            while(!check()) d = (d+1)%4;
            r += dr[d];
            c += dc[d];
        }
        return ans;
    }
};