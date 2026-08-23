class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = INT_MAX;
        for(auto &i: tasks) {
            ans = min(ans, i[0] + i[1]);
        }
        return ans;
    }
};