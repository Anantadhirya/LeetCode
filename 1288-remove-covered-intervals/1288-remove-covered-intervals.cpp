class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        for(auto &i: intervals) {
            ans++;
            for(auto &j: intervals) {
                if(i == j) continue;
                if(j[0] <= i[0] && i[1] <= j[1]) {
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};