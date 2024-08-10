class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(const auto &i: intervals) {
            if(ans.empty() || ans.back()[1] < i[0]) ans.push_back(i);
            else ans.back()[1] = max(ans.back()[1], i[1]);
        }
        return ans;
    }
};