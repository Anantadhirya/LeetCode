class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<vector<int>> ret;
        for(const auto &i: intervals) {
            if(i[1] < newInterval[0] || newInterval[1] < i[0]) {
                ret.push_back(i);
            } else {
                newInterval[0] = min(newInterval[0], i[0]);
                newInterval[1] = max(newInterval[1], i[1]);
            }
        }
        ret.push_back(newInterval);
        for(int i = ret.size()-1; i-1 >= 0; i--) {
            if(ret[i-1][0] > ret[i][0]) swap(ret[i-1], ret[i]);
            else break;
        }
        return ret;
    }
};