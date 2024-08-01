class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(const auto &i: details) {
            ans += stoi(i.substr(11, 2)) > 60;
        }
        return ans;
    }
};