class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<pair<int, int>> v;
        for(const auto &i: nums) {
            if(!v.empty() && v.back().second + 1 == i) {
                v.back().second++;
            } else v.push_back({i, i});
        }
        vector<string> ans;
        for(auto &[a, b]: v) {
            if(a == b) ans.push_back(to_string(a));
            else ans.push_back(to_string(a) + "->" + to_string(b));
        }
        return ans;
    }
};