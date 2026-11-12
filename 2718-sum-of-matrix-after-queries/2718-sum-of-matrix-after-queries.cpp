class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        set<int> r, c;
        long long ans = 0;
        for(int i = queries.size()-1; i >= 0; i--) {
            if(queries[i][0] == 0) {
                // row
                if(r.count(queries[i][1])) continue;
                r.insert(queries[i][1]);
                ans += (long long)(n - c.size()) * queries[i][2];
            } else if(queries[i][0] == 1) {
                // col
                if(c.count(queries[i][1])) continue;
                c.insert(queries[i][1]);
                ans += (long long)(n - r.size()) * queries[i][2];
            }
        }
        return ans;
    }
};