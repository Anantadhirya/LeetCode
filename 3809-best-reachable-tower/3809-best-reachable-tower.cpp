class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> ans = {-1, -1, -1};
        for(auto &i: towers) {
            if(abs(i[0] - center[0]) + abs(i[1] - center[1]) > radius) continue;
            if(i[2] > ans[2]) ans = i;
            else if(i[2] == ans[2]) ans = min(ans, i);
        }
        ans.pop_back();
        return ans;
    }
};