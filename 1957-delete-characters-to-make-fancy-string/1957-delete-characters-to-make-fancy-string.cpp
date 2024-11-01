class Solution {
public:
    string makeFancyString(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        string ans;
        for(const auto &i: s) {
            if(ans.size() >= 2 && ans.back() == i && ans[ans.size()-2] == i) continue;
            ans.push_back(i);
        }
        return ans;
    }
};