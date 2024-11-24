class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sm = 0, mn = LLONG_MAX;
        int cnt = 0;
        for(const auto &i: matrix) {
            for(const auto &j: i) {
                if(j <= 0) {
                    cnt++;
                }
                sm += (long long)abs(j);
                mn = min(mn, (long long)abs(j));
            }
        }
        return cnt&1 ? sm - mn*2 : sm;
    }
};