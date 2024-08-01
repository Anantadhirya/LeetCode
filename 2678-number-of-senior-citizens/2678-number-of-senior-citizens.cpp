class Solution {
public:
    int countSeniors(vector<string>& details) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int ans = 0;
        for(const auto &i: details) {
            ans += stoi(i.substr(11, 2)) > 60;
        }
        return ans;
    }
};