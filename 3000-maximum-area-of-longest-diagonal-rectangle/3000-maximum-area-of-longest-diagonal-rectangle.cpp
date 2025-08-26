class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        pair<double, int> ans = {0, 0};
        for(const auto &i: dimensions) {
            ans = max(ans, {sqrt(i[0]*i[0] + i[1]*i[1]), i[0]*i[1]});
        }
        return ans.second;
    }
};